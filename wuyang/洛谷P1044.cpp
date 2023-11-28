#include <bits/stdc++.h>
using namespace std;
long long int dp[20][20];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            if (j == i) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[n][n] << endl;
    
    return 0;
}