#include <bits/stdc++.h>
using namespace std;
int dp[21003];
int value[50];

int main(){
    int V,n;
    cin>>V>>n;
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=V;j>value[i];j--){
            if(dp[j]<dp[j-value[i]]+value[i]){
                dp[j]=max(dp[j],dp[j-value[i]]+value[i]);
            }
        
        }
    }    
    cout<<V-dp[V]<<endl;
    return 0;
}