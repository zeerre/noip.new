//*************************************************************************
//* File Name: tt.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-10-30  20-41-50====
//*************************************************************************

#include <iostream>
using namespace std;
int bubble(int[],int);

int main() {
    int a[10];
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    printf("%d\n",bubble(a,len));
    for(auto k:a)
        printf("%d\t",k);
    printf("\n");
    return 0;
}

int bubble(int b[],int len){
    int num=0;
    int i,j;
    for(i=0;i<len;i++){
        for(j=0;j<len-i-1;j++){
            if(b[j]>b[j+1]){
                int tem;
                tem=b[j];
                b[j]=b[j+1];
                b[j+1]=tem;
                num++;
            }
        }
    }
    return num;
}
