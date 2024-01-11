/*
贪心 数学规律
2023.11.20
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll; 

int main() {
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n; 
        vector<int> nums(n); 
        for(int& a: nums) cin >> a; 
        int sign = nums.back(); 
        ll ans = 0; 
        for(int i = n - 2; i >= 0; --i) {
            int cnt = (nums[i] - 1) / sign; 
            ans += cnt; 
            sign = nums[i] / (cnt + 1); 
        }
        cout << ans << endl; 
    }
    return 0;
}