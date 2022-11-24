//*************************************************************************
//* File Name: heapsortt.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-11-09  15-43-12====
//*************************************************************************

#include <iostream>
using namespace std;
void heapity(int [],int,int);
void heapsort(int [],int);
int main() {
    int a[]={99,87,45,87,74,64,45,54,12,32,22,8,1,0,1};
    int len=sizeof(a)/sizeof(a[0]);
    heapsort(a,len);
    for(int i=0;i<len;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
void heapity(int a[],int len,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<len && a[l]>a[largest]){
        largest=l;
    }
    if(r<len && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heapity(a,len,largest);
    }
}
void heapsort(int a[],int len){
    for(int i= len/2-1;i>=0;i--){
        heapity(a,len,i);
    }
    for(int i=len-1;i>0;i--){
        swap(a[0],a[i]);
        heapity(a,i,0);
    }
}
