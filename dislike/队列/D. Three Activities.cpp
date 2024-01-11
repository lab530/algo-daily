/*
标签：优先队列，枚举
链接：https://codeforces.com/contest/1914
2023.12.21
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>
using namespace std; 
typedef long long ll; 
struct rule {
    bool operator() (pair<int, int> x, pair<int, int> y) {
        return x.first > y.first; 
    }
}; 

void opt(int n, vector<pair<int, int>>& target) {
    vector<pair<int, int>> nums(n); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, rule> pq; 
    for(int i = 0; i < n; ++i) {
        cin >> nums[i].first; 
        nums[i].second = i; 
        pq.push(nums[i]); 
        if(pq.size() > 3) pq.pop(); 
    }
    while(!pq.empty()) {
        target.push_back(pq.top()); 
        pq.pop(); 
    }
    return; 
}

void solve() {
    int n; cin >> n; 
    vector<pair<int, int>> a, b, c; 
    opt(n, a); 
    opt(n, b); 
    opt(n, c); 
    int ans = 0; 
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                if(a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
                    ans = max(ans, a[i].first + b[j].first + c[k].first); 
                }
            }
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
