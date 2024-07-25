#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
        
    }
    
}

void merge(int arr[],int low,int mid,int high){
    
    int temp[100];
    int left=low;
    int right=mid+1;
    int i=0;
    
    while(left<=mid && right<=high){
        
        if(arr[left]<=arr[right]){
            temp[i++]=arr[left++];
        }
        else{
            temp[i++]=arr[right++];
        }
    }
    
    while(left<=mid){
        temp[i++]=arr[left++];
    }
    
    while(right<=high){
        temp[i++]=arr[right++];
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void merge_sort(int arr[],int low,int high){
    if(low>=high) return;
    
    int mid=(low+high)/2;
    
    //left half
        merge_sort(arr,low,mid);
        
        //right half
        merge_sort(arr,mid+1,high);
        
        merge(arr,low,mid,high);
        
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[]={13,46,24,52,20,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Insertion sort =";
    print(arr,n);
    cout<<endl<<"After sort =";
    int low=0;
    
    int high=n-1;

    merge_sort(arr,low,high);
    print(arr,n);
    
    

    return 0;
}