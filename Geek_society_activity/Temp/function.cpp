//*************************************************************************
//* File Name: function.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-05-09  07-45-24====
//*************************************************************************

// 请将函数体放到此文件中，函数的实现。

#include<cstdio>
#include"function.h"

int CSimple::fibo(int temp)
{
    if (temp==0)
        return 0;
    else if (temp==1)
        return 1;
    else
        return fibo(temp-1) + fibo(temp-2);
}