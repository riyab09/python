#include<iostream>
using namespace std;
int selectionsort(int arr[],int n){
   for(int i=0;i<n-1;i++){
    int min_ind=i;
    for(int j=i+1;j<n;j++){
        if(arr[min_ind]>arr[j]){
            min_ind=j;
        }
    }
    int temp=arr[min_ind];
    arr[min_ind]=arr[i];
    arr[i]=temp;
   }
}


int main(){
    int arr[5], n=5;
    cout<<"enter 5 nos. in array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"unsorted array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    selectionsort(arr,n);

    cout<<"after sorting";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}