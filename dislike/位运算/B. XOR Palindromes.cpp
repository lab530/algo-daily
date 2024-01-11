/*
位运算
2023.12.02
*/
#include <bits/stdc++.h>
using namespace std; 

int cnt(string& s) {
    int left = 0, right = s.size() - 1, res = 0; 
    while(left <= right) {
        if(s[left] != s[right]) ++res; 
        --right; 
        ++left; 
    }
    return res; 
}
void solve() {
    int n; cin >> n; 
    string s, ans(n, '0'); cin >> s; 
    int position = cnt(s); 
    for(int i = 0; i < n; ++i) {
        if(i >= position - 1 && i < n - position) ans[i] = '1'; 
    }
    // 指定位置插入元素，时间复杂度O(n),这个地方应该还有更好的方法
    ans.insert(ans.begin(), ans[n - 1]); 
    if(n % 2 == 0) {
        for(int i = 1; i < n; ++i) {
            if(ans[i] == ans[i - 1] && ans[i] == '1') ans[i] = '0'; 
        }
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
