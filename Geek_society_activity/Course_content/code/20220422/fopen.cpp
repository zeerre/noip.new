//*************************************************************************
//* File Name: fopen.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-04-22  09-18-52====
//*************************************************************************

/* fopen example */
#include <cstdio>
int main ()
{
    FILE * fp;
    fp = fopen ("file.txt","w");
    if (fp!=NULL)
    {
        fputs ("heloo;",fp);
        fclose (fp);
    }
  return 0;
}
