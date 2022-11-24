//*************************************************************************
//* File Name: mergesort.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-11-07  13-56-10====
//*************************************************************************

#include <iostream>
using namespace std;
void merge(int [],int,int,int);
void merge_s(int [],int,int);
int main() {
    int a[]={98,32,56,2,5,2,67,34,12,22,12};
    int len=sizeof(a)/sizeof(a[0]);
    merge_s(a,0,len);
    for(auto v:a){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}
void merge_s(int a[],int start,int end){
    int mid;
    if(start<end){
        mid=(start+end)/2;
        merge_s(a,start,mid);
        merge_s(a,mid+1,end);
        merge(a,start,mid,end);
    }
}
void merge(int *arr,int start,int mid,int end){
    int len=5*(end-start);
    int i,j,k,tem[len];
    i=start;
    k=start;
    j=mid+1;
    while(i<=mid&&j<=end){
        if(arr[i]<arr[j]){
            tem[k]=arr[i];
            i++;
            k++;
        }
        else{
            tem[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        tem[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end){
        tem[k]=arr[j];
        j++;
        k++;
    }
    for(i=start;i<k;i++){
        arr[i]=tem[i];
    }
}
