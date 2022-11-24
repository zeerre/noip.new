//*************************************************************************
//* File Name: radixsortt.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-11-09  09-35-59====
//*************************************************************************

#include <bits/stdc++.h>
using namespace std;
int getmax(int [],int);
void countsort(int [],int ,int);
void radixsort(int [],int);
void printarr(int [],int);
int main() {
    int a[]={99,33,5,32,1,20,34,34,0,232};
    int len=sizeof(a)/sizeof(a[0]);
    radixsort(a,len);
    printarr(a,len);
    return 0;
}
int getmax(int a[],int len){
    int max=a[0];
    for(int i=1;i<len;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void countsort(int a[],int len,int exp){
    const int N=10;
    int output[len];
    int count[N];
    //memset(count,0,sizeof(count));
    for(int i=0;i<N;i++)
        count[i]=0;
    for(int i=0;i<len;i++){
        count[(a[i]/exp)%10]++;
    }
    for(int i=1;i<N;i++){
        count[i]+=count[i-1];
    }
    for(int i=len-1;i>=0;i--){
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0;i<len;i++){
        a[i]=output[i];
    }
}
void radixsort(int a[],int len){
    int m=getmax(a,len);
    for(int exp=1;m/exp>0;exp*=10){
        countsort(a,len,exp);
    }
}
void printarr(int a[],int len) {
    for(int i=0;i<len;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
