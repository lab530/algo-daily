#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;
typedef long long ll;
const ll MAX = numeric_limits<ll>::min();
const ll MIN = numeric_limits<ll>::max();
const ll M = 1e9;

void solve() {
    ll n;
    cin >> n;
    std::vector<ll> nums(n + 1, 0);
    for(ll i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    ll ans = 0;
    for(ll i = n - 1; i >= 1; --i) {
        if(nums[i] > nums[i + 1]) {
            ll s = (nums[i] + nums[i + 1] - 1)/ nums[i + 1];
            nums[i] /= s;
            ans += (s - 1);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
