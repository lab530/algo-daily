/*
数学规律
2023.11.24补11.22
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void solve() {
    int n, k; cin >> n >> k; 
    double temp = (n * 1.0) / k; 
    int ans; 
    // 向上取整
    ans = ceil(temp); 
    if(n % k != 1 && k != 1) ans += 1; 
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
3 2
101
5 2
10101
9 3
100100100 -> 100100101
7 1
1111111
10 4
1000100010 -> 1000100011
9 5
100001000 -> 100001001
8 8
10000000 -> 10000001
*/