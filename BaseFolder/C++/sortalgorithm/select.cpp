//*************************************************************************
//* File Name: st.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com
//* Created And Modified Time: ====2022-10-31  18-38-36====
//*************************************************************************

#include <iostream>
using namespace std;
int selects(int[],int);
int main() {
    int a[]={32,3,42,2,12,21,5,36};
    int len=sizeof(a)/sizeof(a[0]);
    cout<<selects(a,len)<<endl;
    for(auto v:a){
        cout<<v<<"\t";
    }
    cout<<endl;
    return 0;
}

int selects(int a[],int len){
    int i,j;
    int num=0;
    for(i=0;i<len-1;i++){
        int min_index=i;
        for(j=i+1;j<len;j++){
            if(a[j]<a[min_index]){
                min_index=j;
                num++;
            }
        }
        int tem=a[i];
        a[i]=a[min_index];
        a[min_index]=tem;
    }
    return num;
}
