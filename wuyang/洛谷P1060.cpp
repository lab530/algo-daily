#include<bits/stdc++.h>
using namespace std;
long long int dp[100003];

bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first!=y.first)
        return  y.first>x.first;
    else if(x.first==y.first&&x.first!=y.second)
        return y.second>x.second;
    else 
        return x.first>y.first;
}

int main(){
    int T,M;//T为容量
    cin>>T>>M;
    vector<pair<int,int>>num(M);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<M;i++){
        cin>>num[i].first>>num[i].second;//first:容量 second:价值
    }
    sort(num.begin(),num.end(),cmp);
    //状态转移方程
    //cout<<"状态转移"<<endl;
    int j;
    for(int i=0;i<M;i++){
        for(j=T;j>=num[i].first;j--){
            dp[j]=max(dp[j],dp[j-num[i].first]+num[i].second*num[i].first);
            //cout<<"dp"<<dp[j]<<"- ";
        }
        //cout<<"---"<<endl;
    }
    //遍历数组
    //cout<<endl<<"遍历数组"<<endl;
    //for(j=T;j>=num[0].first;j--){
    //    cout<<dp[j]<<" ";
    //}
    long long int cnt=0;
    //输出结果
    //cout<<endl<<"结果"<<endl;
    for(j=T;j>=num[0].first;j--){
        cnt=max(dp[j],cnt);
    }
    cout<<cnt<<endl;

    return 0;
}