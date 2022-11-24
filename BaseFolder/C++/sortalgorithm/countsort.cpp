//*************************************************************************
//* File Name: countsortt.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-11-07  09-50-08====
//*************************************************************************

#include <bits/stdc++.h>
using namespace std;
void counts(int [],int);
int getmax(int [],int);
int main() {
    int a[]={3,21,4,5,5,4,3,2,12,12,3,2,1,1,0};
    int len=sizeof(a)/sizeof(a[0]);
    counts(a,len);
    for(auto v:a){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}
void counts(int a[],int len){
    int max=getmax(a,len);
    int counta[max+1];
    int output[len];
    for(int i=0;i<=max;i++){
        counta[i]=0;
    }
    //memset(count,0,sizeof(count));
    for(int i=0;i<len;i++){
        counta[a[i]]++;
    }
    for(int i=0,j=0;i<=max;i++){
        while(counta[i]>0){
            output[j]=i;
            counta[i]--;
            j++;
        }
    }
    /*
    for(int i=1;i<len;i++){
        count[i]+=count[i-1];
    }
    for(int i=0;i<len;i++){
        output[count[a[i]]-1]=a[i];
    }
    */
    for(int i=0;i<len;i++){
        a[i]=output[i];
    }
}
int getmax(int a[],int len){
    int max=a[0];
    for(int i=1;i<len;i++){
        if(a[i]>=max){
            max=a[i];
        }
    }
    return max;
}
