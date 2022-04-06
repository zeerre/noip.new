//*************************************************************************
//* File Name: 20220319.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-03-19  17-32-16====
//*************************************************************************

#include"stdio.h"
#include<cmath>
using namespace std;
float Func(float,float);
int main(){
    float x,n,outPut=0;
    printf("Please input x&n:\n");
    scanf("%f %f",&x,&n);
    printf("The result is:\n %f",Func(x,n));
    return 0;    
}

float Func(float x,float n){
    float dataSpace;
    int incrNum=0;
    while(incrNum<=n){      //函数循环主体
        incrNum+=1;
        dataSpace=sqrt(x+incrNum);
    }
    return dataSpace;
}
