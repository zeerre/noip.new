//*************************************************************************
//* File Name: function.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-05-09  07-45-24====
//*************************************************************************

// 请将函数体放到此文件中，函数的实现。

#include<stdio.h>
#include<cstring>
char str_1[999],str_2[999],str_3[999];
void case_1();
void case_2();
void case_5();
void case_6();
int main(){
    printf("请输相应数字进行操作：\n 1：测量输入的字符数\n 2：比较输入的两个字符组\n 5：同时显示原输入字符组和修改后的字符组；\n 6：在原输入字符组后接入新字符组；\n");
    int checkPoint;
    scanf("%d\n",&checkPoint);
    if (checkPoint==1)
        case_1();
    if (checkPoint==2)
        case_2();
    if (checkPoint==5)
        case_5();
    if (checkPoint==6)
        case_6();
    return 0;
}

void case_1(){
    printf("请输入：\n");
    fgets(str_1,999,stdin);
    printf("字符数为：\n %ld",strlen(str_1)-1);
}

void case_2(){
    printf("输入字符组1：\n");
    fgets(str_1,999,stdin);
    printf("输入字符组2：\n");
    fgets(str_2,999,stdin);
    if (strcmp(str_1,str_2)==0)
        printf("相同\n");
    else
        printf("不相同\n");
}

void case_5(){
    printf("请输入原字符组（注意！不能超过999个字符！）:\n");
    fgets(str_1,999,stdin);
    strcpy(str_3,str_1);
    printf("请输入新字符组：\n");
    fgets(str_2,999,stdin);
    printf("原字符组：");
    puts(str_3);
    printf("新字符组：");
    puts(str_2);
}

void case_6(){
    printf("请输入原字符组（注意！不能超过999个字符！）:\n");
    fgets(str_3,999,stdin);
    int subTra=strlen(str_3),result;
    result=999-subTra;
    printf("请输入插入字符组，注意！还可插入的字符数为 %d",result);
    fgets(str_1,999,stdin);
    puts(strcat(str_3,str_1));
}