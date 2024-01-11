#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll; 
void solve() {
    ll n; cin >> n; 
    ll min1 = INT64_MAX, min2 = INT64_MAX;
    ll sum1 = 0, sum2 = 0; 
    for(int i = 0; i < n; ++i) {
        ll a; cin >> a; 
        sum1 += a; 
        min1 = min(min1, a); 
    }
    for(int i = 0; i < n; ++i) {
        ll a; cin >> a; 
        sum2 += a; 
        min2 = min(min2, a); 
    }
    ll ans = min(n * min1 + sum2, n * min2 + sum1); 
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