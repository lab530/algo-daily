/*
Educational Codeforces Round 159 (Rated for Div. 2)
2023.12.04
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std; 
typedef long long ll; 

void solve() {
    int n; cin >> n; 
    // unordered_set<ll> st; 
    vector<ll> nums(n), dif; 
    ll Max = INT64_MIN; 
    for(ll& a: nums) {
        cin >> a; 
        // st.insert(a); 
        Max = max(Max, a); 
    }
    for(ll a: nums) {
        if(a == Max) continue; 
        dif.push_back(Max - a); 
    }
    ll GCD; 
    if(n == 1) {
        // GCD = 1; 
        cout << 1 << endl; 
    }
    else if(n == 2) {
        // GCD = abs(nums[0] - nums[1]); 
        cout << 3 << endl; 
    }
    else {
        GCD = __gcd(dif[0], dif[1]); 
        for(int i = 2; i < dif.size(); ++i) {
            // if(__gcd(GCD, dif[i]) == GCD) break; 
            GCD = __gcd(GCD, dif[i]); 
        }
        sort(nums.begin(), nums.end(), greater<ll>()); 
        ll k; 
        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] - nums[i] > GCD) {
                k = nums[i - 1] - GCD; 
                break; 
            }
            if(i == n - 1) k = nums[n - 1] - GCD; 
        }
        dif.push_back(Max - k); 
        ll ans = 0; 
        for(ll a: dif) {
            ans += (a / GCD); 
        }
        cout << ans << endl; 
    }
    return; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}
