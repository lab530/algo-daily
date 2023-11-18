#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int nums[200200] = {0};
int dp[200200] = {0};

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    // dp[1] = nums[1];
    for(int i = 1; i <= n; i++) {
        // -1e3 <= nums[i] <= 1e3, nums[i] % 2 会为负
        if(abs(nums[i - 1] % 2) != abs(nums[i] % 2)) {
            // 
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        } else {
            // 如果相邻的奇偶相同
            dp[i] = nums[i];
        }
    }
    sort(dp + 1, dp + n + 1);
    cout << dp[n] << '\n';

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}