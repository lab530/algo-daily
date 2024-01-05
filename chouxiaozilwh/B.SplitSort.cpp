#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int loc[100100] = {0};
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        loc[num] = i;
    }
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(loc[i] < loc[i - 1]) ans++;
    }
    cout << ans << '\n';

}

// tle
// void solve() {
//     int n;
//     cin >> n;
//     int nums[100100] = {0};
//     for(int i = 0; i < n; i++) cin >> nums[i];
//     int ans = 0;
//     int p = 1;
//     while(p != n) {
//         ans++;
//         for(int i = 0; i < n; i++) {
//             if(p == nums[i]) p++;
//         }
//     }
//     cout << ans << '\n';
// }

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}