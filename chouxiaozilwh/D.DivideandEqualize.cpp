#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

// 计算 x 的所有素数因子
// 50: 2, 5, 5
// 30: 2, 3, 5
void add_divs(int x, map<int, int> &divs) {
    for(int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            divs[i]++;
            x /= i;
        }
    }
    if(x > 1) divs[x]++;
}

// 计算所有数的积开 n 次方是否为整数(10e6 ^ 10e4 -> 爆 long long)
// 计算所有数的素数因子的个数 看看每个素数因子 % n 是否为 0
void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    map<int, int> divs;
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
        add_divs(vec[i], divs);
    }

    bool flag = 1;
    for(auto d : divs) {
        if(d.second % n != 0) {
            flag = 0;
            break;
        }
    }
    if(flag) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}