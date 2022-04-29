//

#include<cstdio>
#include<fstream>
using namespace std;

//方法一：文件输入输出流

int main(){
    ifstream inPut_1("in.txt");
    ofstream outPut_1("out.txt");
    int temp,result=0;
    while (inPut_1>>temp)
    {
        result+=temp;
    }
    outPut_1<<result<<endl;
    inPut_1.close();
    outPut_1.close();
    return 0;
}

//方法二：重定向

void REopen(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    FILE *inPut_2=stdin,*outPut_2=stdout;
    int temp_re,result_re=0;
    while (fscanf(inPut_2,"%d",&temp_re)==1)
    {
        result_re+=temp_re;
    }
    fprintf(outPut_2,"%d",result_re);
    fclose(stdin);fclose(stdout);
}

//方法三：文件访问

void open(){
    FILE *inPut_3,*outPut_3;
    inPut_3=fopen("in.txt","rb");
    outPut_3=fopen("out.txt","wb");
    int temp_o,result_o=0;
    while (fscanf(inPut_3,"%d",&temp_o)==1)
    {
        result_o+=temp_o;
    }
    fprintf(outPut_3,"%d",result_o);
    fclose(inPut_3);fclose(outPut_3);
}