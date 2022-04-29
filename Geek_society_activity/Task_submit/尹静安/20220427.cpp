//

void fabonacci(int,int);
int main(){
    FILE *inputNUM;
    inputNUM=fopen("in.txt","rb");
    int inputNum;
    for (int i=1;i<=2;i++){
        fscanf(inputNUM,"%d",&inputNum);    //小写尾缀是变量，大写尾缀是指针
        arr_2[i]=inputNum;
    }
    arr_1[1][1]=1;
    fabonacci(arr_2[0],arr_2[1]);
    return 0;
}

void fabonacci(int Hlmt,int Olmt){  //"H"为横行，"O"为纵列
    int Htemp=2,Otemp=1;
    while (Htemp<=Hlmt && Otemp<=Olmt){
        if (Htemp==Otemp){
            arr_1[Htemp][Otemp]=1;
            Htemp+=1;
            Otemp=1;
        }
        else{
            arr_1[Htemp][1]=1;
            arr_1[Htemp][Otemp]=arr_1[Htemp-1][Otemp-1]+arr_1[Htemp-1][Otemp];
            Otemp+=1;
        }
    }
    printf("The result is:\n %d",arr_1[Htemp][Otemp]);
}