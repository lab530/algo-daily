/*
CodeTON Round 7 (Div. 1 + Div. 2, Rated, Prizes!)
2023.11.28
*/
// 排序、二分
#include <bits/stdc++.h>
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

// 结构体、排序
// #include <bits/stdc++.h>

// using namespace std; 

// struct beauty {
// 	int a; 
// 	int b; 
// 	int id; 
// } nums[1000010]; 

// struct rule_a {
// 	bool operator() (const beauty& x, const beauty& y) {
// 		return x.a > y.a; 
// 	}
// };

// struct rule_id {
// 	bool operator() (const beauty& x, const beauty& y) {
// 		return x.id < y.id; 
// 	}
// };

// void solve() {
// 	int n, x; cin >> n >> x; 
// 	for(int i = 0; i < n; ++i) {
// 		cin >> nums[i].a; 
// 		nums[i].id = i; 
// 	}
// 	sort(nums, nums + n, rule_a()); 
// 	vector<int> nums_b(n); 
// 	for(int& m: nums_b) cin >> m; 
// 	sort(nums_b.begin(), nums_b.end()); 
// 	sort(nums_b.begin(), nums_b.begin() + x, greater<int>()); 
// 	sort(nums_b.begin() + x, nums_b.end(), greater<int>()); 
// 	bool sign = true; 
// 	for(int i = 0; i < n; ++i) {
// 		if(i < x && nums[i].a <= nums_b[i] || i >= x && nums[i].a > nums_b[i]) sign = false; 
// 		nums[i].b = nums_b[i]; 
// 	}
// 	if(!sign) cout << "NO" << endl; 
//     else {
//         cout << "YES" << endl; 
// 		sort(nums, nums + n, rule_id()); 
// 		for(int i = 0; i < n; ++i) cout << nums[i].b << ' '; 
//         cout << endl; 
//     }
// 	return; 
// }

// int main() {
// 	int t; cin >> t; 
// 	while(t--) {
// 		solve(); 
// 	}
// 	return 0; 
// }
