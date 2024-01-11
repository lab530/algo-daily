/*
链接：https://codeforces.com/contest/1919/problem/C
2024.01.11, hello 2024
*/
/*
    cout << "int 最大值：" << INT_MAX << '\n';
    cout << "int 最小值：" << INT_MIN << '\n';
    cout << "float 最大值：" << FLT_MAX << '\n';
    cout << "float 最小值：" << FLT_MIN << '\n';
    cout << "double 最大值：" << DBL_MAX << '\n';
    cout << "double 最小值：" << DBL_MIN << '\n';
    cout << "long 最大值：" << LONG_MAX << '\n';
    cout << "long 最小值：" << LONG_MIN << '\n';
    cout << "long long 最大值：" << LONG_LONG_MAX << '\n';
    cout << "long long 最小值：" << LONG_LONG_MIN << '\n';
    cout << "unsigned long long 最大值：" << ULONG_LONG_MAX << '\n';
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

void solve() {
    int n; cin >> n; 
    vector<ll> nums(n); 
    for(int i = 0; i < n; ++i) {
        cin >> nums[i]; 
    }
    ll a = INT_MAX, b = INT_MAX, cnt = 0; // a为一个子序列的尾元素，b为另一个子序列的尾元素
    // 初始化很关键，比如 1 2 1 结果是 0
    // 1 1 2 结果也应该是 0
    for(int i = 0; i < n; ++i) {
        int x = nums[i]; 
        if(a == x || b == x) continue; 
        else if(a > x && b < x) a = x; 
        else if(a < x && b > x) b = x; 
        else if(a > x && b > x) {
            if(a < b) a = x; 
            else b = x; 
        }
        else {
            if(a < b) a = x; 
            else b = x; 
            ++cnt; 
        }
    }
    cout << cnt << endl; 
    return; 
}

int main() {
    int t; cin >> t; 
    // int t; t = 0; 
    while(t--) {
        solve(); 
    }
    return 0; 
}

