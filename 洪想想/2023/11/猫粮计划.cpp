#include<bits/stdc++.h>
using namespace std;
int n,l,r,cnt = 0;
int much = 0;
int w[60];
void f(int k){
    for(int i = k + 1;i <= n; ++i){
        much += w[i];//累加重量
        //cout<<much<<endl;//最高也不会超过90
        if(much >= l && much <= r){
            cnt++;//方案的数量加一
        }else if(much > r){//如果超出了范围，那么就不能再往后考虑了
            much -= w[i];//还原
            //continue;
            return  ;
        }
        f(i);
        much -= w[i];//减掉这个累加的值，为后面的计算
    }
    return ;
}
int main(){
    cin >> n >> l >> r;
    for(int i = 1;i <= n; ++i){
        cin >> w[i];//存入每个粮食的热量值
    }
    sort(w+1,w+1+n);//排序，为了等会更好的调用深搜
    f( 0);
    cout << cnt;//输出结果
    return 0;
}