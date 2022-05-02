//

#include<cstdio>
using namespace std;
int arr_i[2];   //用于接收输入
int arr_f[999][999];    //用于形成斐波那契数列
int fibo(int);
void print(int,int);    //输出函数，两个变量即目标对象的横、纵坐标
int main(){
    FILE *INPUT;
    INPUT=fopen("in.txt","rb");
    int temp_1,temp_2;
    for (int i=1; i<=2; i++){
        fscanf(INPUT,"%d",&temp_1);
        arr_i[i]=temp_1;
    }
    temp_2=fibo(arr_i[1]);
    print(temp_2,arr_i[2]);
    return 0;   
}

int fibo(int h_std){
    int retu_H=2;
    arr_f[1][1]=1;
    for (int h=2; h<=h_std-1; h++){
        arr_f[h][1]=1;
        arr_f[h][h]=1;
        retu_H++;
        for (int o=2; o<=h-1; o++)
        arr_f[h][o]=arr_f[h-1][o-1] + arr_f[h-1][o];
    }
    return retu_H;  //返回目标对象的行序数
}

void print(int a,int b){
    printf("The result is:\n %d",arr_f[a][b]);
}