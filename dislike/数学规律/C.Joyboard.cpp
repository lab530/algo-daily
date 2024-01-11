/*
数学规律
2023.11.21
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <deque>

using namespace std;

typedef long long ll; 

// 暴力TLE
// void solve() {
//     int n, m, k; cin >> n >> m >> k; 
//         int ans = 0; 
//         while(m >= 0) { 
//             int sign = m, cnt = 1; 
//             for(int i = n; i >= 1; --i) {
//                 int front = sign; 
//                 sign = sign % i; 
//                 if(front != sign) ++cnt; 
//                 if(sign == 0) break; 
//             }
//             if(cnt == k) ++ans; 
//             --m; 
//         }
//     cout << ans << endl; 
// }

void solve() {
    int n, m, k; cin >> n >> m >> k; 
    int ans = 0; 
    if(k >= 4) ans = 0; 
    else if(k == 3) {
        ans = m - (m / n) - n + 1; 
        ans = max(ans, 0); 
    }
    else if(k == 2) {
        ans += (m / n) + n - 1; 
        ans = min(ans, m); 
    }
    else {
        ans = 1; 
    }
    cout << ans << endl;  
}

int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0;
}


/*
k 只有三种情况
1 m == 0
2 1 <= m <= n || m % n == 0
3 m > n && m % n != 0
*/