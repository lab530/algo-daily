// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll; 
int search(vector<pair<int, int>>& vt, int target) {
    int left = 0, right = vt.size() - 1; 
    while(left <= right) {
        int mid = (left + right) / 2; 
        if(vt[mid].first < target) right = mid - 1; 
        else if(vt[mid].first > target) left = mid + 1; 
        else right = mid - 1; 
    }
    int ans, i = left; 
    while(vt[i].second == 0) ++i; 
    ans = vt[i].second; 
    vt[i].second = 0; 
    return ans; 
}

void solve() {
    int n, x; cin >> n >> x; 
    vector<int> a(n), b(n), nums; 
    for(int& m: a) cin >> m; 
    nums = a; 
    for(int& m: b) cin >> m; 
    sort(a.begin(), a.end(), greater<int>()); 
    sort(b.begin(), b.end()); 
    sort(b.begin(), b.begin() + x, greater<int>()); 
    sort(b.begin() + x, b.end(), greater<int>()); 
    vector<pair<int, int>> vt; 
    bool sign = true; 
    for(int i = 0; i < n; ++i) {
        if(i < x && a[i] <= b[i] || i >= x && a[i] > b[i]) sign = false; 
        if(sign) vt.push_back(make_pair(a[i], b[i])); 
    }
    if(!sign) cout << "NO" << endl; 
    else {
        cout << "YES" << endl; 
        for(int m: nums) cout << search(vt, m) << ' '; 
        cout << endl; 
    }
    return; 
}

int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}
