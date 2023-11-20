#include<iostream>
#include<algorithm>
using namespace std;

struct thing{
    int lo,wi;
}t[5005];

bool cmp(thing &a,thing &b){
    if(a.lo==b.lo)return a.wi>b.wi;
    return a.lo>b.lo;
}//定义比较函数
bool used[5005]={};//是否被处理过
int main(){
    int n,sum=0,twi;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].lo;
        cin>>t[i].wi;
    }//输入
    sort(t+1,t+n+1,cmp);//排序
    for(int i=1;i<=n;i++){
        if(used[i]==0){//如果这个木棍被处理过就跳过
            twi=t[i].wi;//保存现有宽度
            for(int j=i+1;j<=n;j++){//向后搜索
                if(t[j].wi<=twi && used[j]==0){//如果有宽度小于现有宽度且没有被处理过
                    used[j]=1;//处理这个木棍
                    twi=t[j].wi;//保存这个木棍的宽度，因为时间加一，从这个棍子的代码开始作为考虑点
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(used[i]==0){
            sum++;//如果没用过就加1分钟
        }
    }
    cout<<sum;//输出
    return 0;
}