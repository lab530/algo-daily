/*
链接：https://codeforces.com/contest/1904
枚举
2023.12.13
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool judge(vector<pair<int, int>>& vct, pair<int, int> target) {
    for(int i = 0; i < vct.size(); ++i) {
        if(vct[i] == target) return false; 
    }
    return true; 
}
void solve() {
    int a, b; cin >> a >> b; 
    int xk, yk; cin >> xk >> yk; 
    int xq, yq; cin >> xq >> yq; 
    // 这里认真学一下
    int dx[8] = {a, a, -a, -a, b, b, -b, -b}; 
    int dy[8] = {b, -b, b, -b, a, -a, a, -a}; 
    vector<pair<int, int>> vct1, vct2; 
    int ans = 0; 
    for(int i = 0; i < 8; ++i) {
        if(judge(vct1, make_pair(xk + dx[i], yk + dy[i]))) vct1.push_back(make_pair(xk + dx[i], yk + dy[i])); 
    }
    for(int i = 0; i < 8; ++i) {
        if(judge(vct2, make_pair(xq + dx[i], yq + dy[i]))) vct2.push_back(make_pair(xq + dx[i], yq +dy[i])); 
    }
    for(int i = 0; i < vct1.size(); ++i) {
        for(int j = 0; j < vct2.size(); ++j) {
            if(vct1[i] == vct2[j]) ++ans; 
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
