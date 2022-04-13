//*************************************************************************
//* File Name: 20220319.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-03-19  17-32-16====
//*************************************************************************

#include"stdio.h"
#include<cmath>
using namespace std;
float Fuc(float,float,float);
int main(){
    float x,n;
    printf("Please input x&n:\n");
    scanf("%f %f",&x,&n);
    printf("The result is:\n %f",Fuc(x,n,0));
    return 0;
}

float Fuc(float x,float n,float tempAlgebra){   //三个变量，分别是：x,n和上一轮计算出的平方根值
    if(n==1){
        tempAlgebra+=sqrt(1+x);
        return tempAlgebra;
    }
    else{
        tempAlgebra+=sqrt(n);
        n--;
        return Fuc(x,n,tempAlgebra);
    }       
}
