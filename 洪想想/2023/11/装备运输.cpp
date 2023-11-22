#include<bits/stdc++.h>
using namespace std;
int ku[505][505];//创建三维数组作为背包
struct thing{
    int t,v,g;
}zd[505];
int main(){
    int v,g,n,t,maxv,maxg;
    cin>>maxv>>maxg;//表示最大体积和重量
    cin>>n;//表示仓库有多少个装备
    for(int i=1;i<=n;i++){
        cin>>zd[i].t>>zd[i].v>>zd[i].g;
    }
    //ku[1][1][1]=-INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=maxv;j>=1;j--){
            for(int k=maxg;k>=1;k--){
                if(j-zd[i].v>=0 && k-zd[i].g>=0){
                    ku[j][k]=max(ku[j][k],ku[j-zd[i].v][k-zd[i].g]+zd[i].t);
                }else{
                    ku[j][k]=ku[j][k];
                }
            } 
        }
    }
    cout<<ku[maxv][maxg]<<endl;
    return 0;
}