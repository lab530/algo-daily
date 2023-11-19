#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        deque<int> nums(n, 0);
        int maxx = INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            maxx = max(maxx, nums[i]);
        }
        deque<int> arr;
        bool flag = 0;
        for(int i = 0; i <= maxx; i++) {
            auto num = find(nums.begin(), nums.end(), i);
            if(num == nums.end()) {
                flag = 1;
                arr.push_back(i);
            }
        }
        if(!flag) nums.push_front(maxx + 1);
        for(auto a : arr) {
            nums.push_front(a);
        }

        // for(auto a : nums) cout << a << ' ';
        // cout << '\n';

        k = k % (n + 1) - 1;
        // if(arr.size() > 1) --k;
        if(!k) {
            for(int i = 0; i < n; i++) cout << nums[i] << ' ';
            cout << '\n';
        } else {
            for(int i = (n + 1) - k, count = 0; count < n; i++, count++) {
                i %= (n + 1);
                cout << nums[i] << ' ';
            }
            cout << '\n';
        }

    }
    return 0;
}