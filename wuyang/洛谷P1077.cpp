#include<bits/stdc++.h>
using namespace std;
int dp[101][101];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int>nums(n+1);
    for (int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            for(int k = 0; k <= min(j,nums[i]); ++k){
                dp[i][j] = (dp[i][j] + dp[i-1][j-k])%1000007;
            }
        }
    } 

    // for (int i = 0; i <= n; ++i){
    //     for (int j = 0; j <= m; ++j){
    //         cout << "dp=" << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][m];
    return 0;
}