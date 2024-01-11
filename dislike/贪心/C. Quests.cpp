/*
标签：贪心，前缀和
链接：https://codeforces.com/contest/1914
2023.12.21
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
    ll n, k; cin >> n >> k; 
    vector<ll> a(n), b(n); 
    for(ll& num: a) cin >> num; 
    for(ll& num: b) cin >> num; 
    ll pfx = 0, mx = 0, ans = 0; 
    for(int i = 0; i < min(n, k); ++i) {
        pfx += a[i]; 
        mx = max(mx, b[i]); 
        ans = max(ans, pfx + (k - i - 1) * mx); 
    }
    cout << ans << endl; 
    return; 
}

int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}
