//*************************************************************************
//* File Name: buckets.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-11-01  21-23-34====
//*************************************************************************

#include <iostream>
using namespace std;
int getmax(int[],int);
void buckets(int[],int);
void printarr(int[],int);
int main() {
    int a[]={98,23,12,6,2,76,54,3,34,5,85};
    int len=sizeof(a)/sizeof(a[0]);
    cout<<"Befor sort:\n";
    printarr(a,len);
    buckets(a,len);
    cout<<"After sort:\n";
    printarr(a,len);
    return 0;
}

int getmax(int a[],int len){
    int max=a[0];
    for(int i=0;i<len;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void buckets(int a[],int len){
    int max=getmax(a,len);
    int bucket[max];
    for(int i=0;i<=max;i++){
        bucket[i]=0;
    }
    for(int i=0;i<len;i++){
        bucket[a[i]]++;
    }
    for(int i=0,j=0;i<=max;i++){
        while(bucket[i]>0){
            a[j++]=i;
            bucket[i]--;
        }
    }
}
void printarr(int a[],int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
