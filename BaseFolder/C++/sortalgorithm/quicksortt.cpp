//*************************************************************************
//* File Name: quicksortt.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-11-05  20-39-31====
//*************************************************************************

#include <iostream>
using namespace std;
int partition(int[],int,int);
void quicksort(int[],int,int);
int num=0;
int main() {
    int a[]={98,89,32,64,67,72,1,34,21,12,65,0,45,54};
    int n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n);
    for(auto v:a){cout<<v<<"  ";}
    cout<<endl;
    cout<<"Totle times: "<<num<<endl;
    return 0;
}
int partition(int a[],int start,int end){
    int pivot=a[start];
    int count=0;
    for(int i=start+1;i<end;i++){
        if(a[i]<=pivot) count++;
    }
    int indexpivot=start+count;
    swap(a[indexpivot],a[start]);
    int i=start,j=end;
    while(i<indexpivot&&j>indexpivot){
        while(a[i]<=pivot)  i++;
        while(a[j]>=pivot)  j--;
        if(i<indexpivot&&j>indexpivot){
            swap(a[i++],a[j--]);
        }
    }
    return indexpivot;
}
void quicksort(int a[],int start,int end){
    num++;
    if(start>end)   return;
    int p=partition(a,start,end);
    quicksort(a,start,p-1);
    quicksort(a,p+1,end);
    //return num;
}
