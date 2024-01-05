#include<bits/stdc++.h>
using namespace std;

bool isprime(int a){
    for(int i = 2;i * i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}

int n,k;
int a[25];
long long ans;

void dfs(int m, int sum, int startx){

    if(m == k){//如果选完了的话
        if(isprime(sum))//如果和是素数
            ans++;//ans加一
        return ;
    }
    for(int i = startx; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);//递归
        //步数要加一，和也要加
    return ;
}

int main(){
    cin>>n>>k;
    
    for(int i = 0; i < n; i++)
        cin>>a[i];
    dfs(0,0,0);//调用函数
    cout<<ans;
    return 0;
}