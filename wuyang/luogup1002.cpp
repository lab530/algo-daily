#include<bits/stdc++.h>
using namespace std;
long long int dp[50][50];
long long int obs[50][50];
int main(){
    int n,m;//终点坐标
    cin>>n>>m;
    n+=2;
    m+=2;
    int x,y;//马坐标
    cin>>x>>y;
    x+=2;
    y+=2;
    obs[x][y]=obs[x-1][y-2]=obs[x-2][y-1]=obs[x+1][y-2]=obs[x+2][y-1]=obs[x+2][y+1]=obs[x+1][y+2]=obs[x-1][y+2]=obs[x-2][y+1]=1;
    for(int i=2;i<=n&&obs[i][2]!=1;i++)dp[i][2]=1;
    for(int i=2;i<=m&&obs[2][i]!=1;i++)dp[2][i]=1;  
    for(int i=3;i<=n;i++){      
        for(int j=3;j<=m;j++){         
            dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
            dp[x][y]=dp[x-1][y-2]=dp[x-2][y-1]=dp[x+1][y-2]=dp[x+2][y-1]=dp[x+2][y+1]=dp[x+1][y+2]=dp[x-1][y+2]=dp[x-2][y+1]=0;          
        }
    }

    cout<<dp[n][m]<<endl;
    return 0;
}