//*************************************************************************
//* File Name: 20220319.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-03-19  17-32-16====
//*************************************************************************

#include"stdio.h"
#include<stdlib.h>
using namespace std;
int main(){
    printf("Are you ready to coding?\n Press y/n for yes/no;\n");
    char tem;       
    scanf("%c",&tem);       //键盘输入
    int turn;      
    turn=tem;    //转换变量为整形方便判断
    if(turn==121)
        printf("Hello,World!\n");
    else
        printf("Well,we're still waiting for you!\n");
    system("pause");
    return 0;
}
