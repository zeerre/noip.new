//

#include<cstdio>
using namespace std;
int fibo(int);
int main(){
    FILE *INPUT;
    INPUT=fopen("in.txt","rb");
    printf("Please write the ordnum in the 'in.txt'\n");
    int temp,outPut;
    fscanf(INPUT,"%d",&temp);
    outPut=fibo(temp);
    printf("The result is:\n %d",outPut);
    return 0;
}

int fibo(int temp_f){
    if (temp_f==0)
        return 0;
    else if (temp_f==1)
        return 1;
    else
        return fibo(temp_f-1) + fibo(temp_f-2);
}