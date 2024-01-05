#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> nums[i];

    if(nums[1] != n) {
        cout << "No" << '\n';
        return ;
    } else {
        vector<int> vec(1, 0);
        for(int i = n; i >= 1; --i) {
            while(vec.size() <= nums[i]) vec.push_back(i);
        }
        
        bool flag = 1;
        for(int i = 1; i <= n; i++) {
            if(nums[i] != vec[i]) {
                flag = 0;
                break;
            }
        }
        if(flag) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}