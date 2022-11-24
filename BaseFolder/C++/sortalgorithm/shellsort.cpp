//*************************************************************************
//* File Name: shellsortt.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-11-08  15-32-11====
//*************************************************************************

#include <iostream>
using namespace std;
void shellsort(int [],int);

int main() {
    int a[]={87,45,32,2,1,4,6,7,1,0};
    int len=sizeof(a)/sizeof(a[0]);
    shellsort(a,len);
    for(auto v:a)
        cout<<v<<" ";
    cout<<endl;
    return 0;
}

void shellsort(int a[],int len){
    for(int interval=len/2;interval>0;interval/=2){
        for(int i=interval;i<len;i+=1){
            int temp=a[i];
            int j;
            for(j=i;j>=interval && a[j-interval]>temp;j-=interval){
                a[j]=a[j-interval];
            }
            a[j]=temp;
        }
    }
}
