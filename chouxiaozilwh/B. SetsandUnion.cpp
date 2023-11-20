#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int mar[55][55];
        set<int> s;
        vector<set<int>> vs(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> mar[i][0];
            for(int j = 1; j <= mar[i][0]; j++) {
                cin >> mar[i][j];
                s.insert(mar[i][j]);
                vs[i].insert(mar[i][j]);
            }
        }
        // int maxx = s.size();
        // cout << maxx << '\n';

        // 去除 S 中的某一个值, 寻找不包含最大的并集
        int ans = 0;
        for(auto a : s) {
            set<int> tmp;
            for(int i = 1; i <= n; i++) {
                auto b = vs[i].find(a);
                if(b == vs[i].end()) {
                    for(int j = 1; j <= mar[i][0]; j++) {
                        tmp.insert(mar[i][j]);
                    }
                }
            }
            // for(auto c : tmp) cout << c << ' ';
            // cout << '\n';
            int sizet = tmp.size();
            ans = max(ans, sizet);
        }
        cout << ans << '\n';

    }
    return 0;
}