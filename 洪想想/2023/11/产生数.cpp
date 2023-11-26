#include <iostream>
#include <cstring>
using namespace std;
int tag[10][10];//创建一个二维数组，用来存0-9的变量变化次数
int d[10];
int p[1000];
int main()
{
    string a;//创建字符串
    int n;
    while(cin>>a>>n)//当输入不停止的时候
    {
        int x,y;
        for(int i=0;i<n;i++)//就是题目中的k值，即规则次数
        {
            cin>>x>>y;//把规则存入二维数组
            tag[x][y]=1;
        }
    for(int k=1;k<=9;k++)//因为不能把数变成0，所以可以直接排除k=0的情况
        for(int i=0;i<=9;i++)
            for(int j=1;j<=9;j++)//因为不能把数变成0，所以可以直接排除j=0的情况
                if(tag[i][k] && tag[k][j]) tag[i][j]=1;//寻找可以间接转化的数
        for(int i=0;i<10;i++)
        {
            tag[i][i]=1;
            for(int j=0;j<10;j++)
                if(tag[i][j])
                d[i]++;//计算每个数字可以转换的次数
        }
        int z;
        p[0]=1;//为了下方的for循环可以运行
        for(int i=0;a[i];i++){//遍历输入的那个数
            z=0;
            int x=d[a[i]-'0'];//寻找每个位代表的数字下标，看看那个数字可以被转化几次
            /*if(x!=0){
                z=z*x;
            }*/
            for(int i=0;i<500;i++){//遍历500次 
                p[i]=(p[i]*x+z);//初始值为1，*上想，等于乘上可能结果，但是z的初始值为0，所以不用考虑第一次的结果
                z=p[i]/10;
                p[i]%=10;//等于判断以为，取余
            }
        }
        int i=500;
        while(p[i]==0) i--;//只要i对应的位子不是非0，也就是说没定义过的话，就i--
        for(;i>=0;i--)//遍历i只要i大于0，就输出p[i]！！！
        {
            cout<<p[i];//p[i]就是最终结果
        }
        /*for(int i=0;i<10;i++){
            if(d[i]!=0){
                z=z*d[i];
            }
        }                               
        cout<<z;*/
    }
    return 0;
}