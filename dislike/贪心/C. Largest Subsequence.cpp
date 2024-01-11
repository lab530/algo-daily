/*
链接：https://codeforces.com/contest/1905
2023.12.17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bool compare(string& ans) {
//     for(int i = 0; i < ans.size() - 1; ++i) {
//         if(ans[i] > ans[i + 1]) return false; 
//     }
//     return true; 
// }
void solve() {
    int n; cin >> n; 
    string s; cin >> s; 
    vector<bool> judge(n, false); 
    int cnt = 0, repeat = 0; 
    char sign = s.back(); 
    judge.back() = true; 
    vector<char> vct; 
    vct.push_back(sign); 
    for(int i = n - 2; i >= 0; --i) {
        if(s[i] >= sign) {
            sign = s[i]; 
            vct.push_back(sign); 
            judge[i] = true; 
            ++cnt; 
        }
    }
    string ans; 
    int j = 0; 
    for(int i = 0; i < n; ++i) {
        if(judge[i] == false) ans.push_back(s[i]); 
        else {
            ans.push_back(vct[j]); 
            ++j;  
        }
    }
    for(int i = vct.size() - 2; i >= 0; --i) {
        if(vct[i] == vct.back()) ++repeat; 
        else break; 
    }
    // if(compare(ans)) cout << (cnt - repeat) << endl; 
    if(is_sorted(ans.begin(), ans.end())) cout << (cnt - repeat) << endl; 
    else cout << -1 << endl; 
    return; 
}
int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0;
}
