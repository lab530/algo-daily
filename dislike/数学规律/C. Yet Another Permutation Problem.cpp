/*
2023.12.03
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
    vector<int> ans(1, 1); 
    unordered_set<int> st; 
    for(int i = 2; i <= n; ++i) {
        for(int j = i; j <= n; j *= 2) {
            if(!st.count(j)) {
                ans.push_back(j); 
                st.insert(j); 
            }
            else break; 
        }
        if(!st.count(i)) ans.push_back(i); 
    }
    for(int a: ans) cout << a << ' '; 
    cout << endl; 
    return; 
}
int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}
