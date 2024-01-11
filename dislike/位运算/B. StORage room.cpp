/*
Create B. StORage room.cpp
链接：https://codeforces.com/contest/1903/problem/B
Codeforces Round 912 (Div. 2)
位运算
2023.12.01
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
    // 二维数组初始化
    vector<vector<ll>> nums(n, vector<ll>(n, 0)); 
    vector<ll> ans; 
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> nums[i][j]; 
        }
    }
    // for(int i = 0; i < n; ++i) {
    //     vector<ll> small(n); 
    //     for(ll& a: small) cin >> a; 
    //     nums.push_back(small); 
    // }
    ll mem; 
    for(int i = 0; i < n; ++i) {
        mem = 2e30 - 1; 
        if(n == 1) mem = 1; 
        for(int j = 0; j < n; ++j) {
            if(i == j) continue; 
            mem &= nums[i][j]; 
        }
        // cout << mem << ' '; 
        ans.push_back(mem); 
    }
    // for(ll a: ans) cout << a << ' '; 
    // cout << endl; 
    bool sign = false; 
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            // 这个地方必须要打括号，优先级：按位或优先级在不等于号之后
            if((ans[i] | ans[j]) != nums[i][j]) {
                sign = true; 
                break; 
            }
        }
        if(sign) break; 
    }
    if(sign) cout << "NO" << endl; 
    else {
        cout << "YES" << endl; 
        for(ll a: ans) cout << a << ' '; 
        cout << endl; 
    }
} 
int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}
