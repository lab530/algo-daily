#include <bits/stdc++.h>
using namespace std;
int dp[350000];
int nums[200002];

int main(){
    int n;
    cin >> n;
    int max1 = -9999999;
    for (register int j = 1; j <= n; ++j){
        cin >> nums[j];
        dp[j] = max(dp[j-1] + nums[j], nums[j]);
        max1 = max(max1,dp[j]);
    }
    cout << max1;

    return 0;
}