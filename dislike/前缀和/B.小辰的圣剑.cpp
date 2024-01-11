/*
牛客小白月赛81：https://ac.nowcoder.com/acm/contest/69791/B
前缀和
2023.11.18
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll; 
int main()
{
    ll n, m, u; cin >>n >> m >> u; 
    vector<ll> a(n), b(n); 
    for(ll& i: a) cin >> i; 
    for(ll& i: b) cin >> i; 
    ll ans = 0; 
    for(int i= 0; i < n; ++i) {
        ll sum1 = 0, sum2 = 0, day = 0; 
        for(int j = i; j < n; ++j) {
            sum1 += a[j]; 
            sum2 += b[j]; 
            if(sum1 > m || sum2 > u) break; 
            ++day; 
        }
        ans = max(ans, day); 
    }
    cout << ans << endl; 
    return 0;
} 