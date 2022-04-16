//

#include"stdio.h"
#include<cmath>
using namespace std;
float Fuc(float,float,float);
int main(){
    float x,n;
    printf("Please input x&n:\n");
    scanf("%f %f",&x,&n);
    printf("The result is:\n %f",Fuc(x,n,1));
    return 0;
}

float Fuc(float x,float n,float countTimes){   //三个变量，分别是：x,n和从1递增到n的计数   
    if(countTimes==n){
        x=sqrt(x+n);
        return x;
    }   
    else{
        x=sqrt(x+countTimes);
        countTimes++;
        return Fuc(x,n,countTimes);
    }
}