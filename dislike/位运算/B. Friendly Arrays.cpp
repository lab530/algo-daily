/*
位运算
2023.12.07
*/
#include <iostream>
#include <vector>
using namespace std; 
void solve() {
    int n, m; cin >> n >> m; 
    vector<int> nums_a(n), nums_b(m); 
    int k = 0; 
    for(int& a: nums_a) {
        cin >> a; 
        k ^= a; 
    } // 不选b
    int q = 0, b = 0; 
    for(int& a: nums_b) {
        cin >> a; 
        b |= a; 
    }
    for(int a: nums_a) {
        q ^= (a | b); 
    }
    // cout << q << endl; 
    if(k > q) cout << q << ' ' << k << endl; 
    else cout << k << ' ' << q << endl; 
    return; 
}

int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}
