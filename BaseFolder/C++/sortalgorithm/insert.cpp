//*************************************************************************
//* File Name: it.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-10-30  20-58-28====
//*************************************************************************

#include <iostream>
using namespace std;
int inserts(int[],int);
int main() {
    int a[]={32,12,31,10,2,8,23,65,43};
    int len=sizeof(a)/sizeof(a[0]);
    cout<<inserts(a,len)<<endl;
    for(auto v:a){
        cout<<v<<"\t";
    }
    cout<<endl;
    return 0;
}

int inserts(int b[],int len){
    int i,j,tem;
    int num=0;
    for(i=1;i<len;i++){
        tem=b[i];
        j=i-1;
        while(j>=0 && b[j]>tem){
            b[j+1]=b[j];
            j--;
            num++;
        }
        b[j+1]=tem;
    }
    return num;
}
