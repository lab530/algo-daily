#include <iostream>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 1) {
        cout << 1 << '\n';
        return ;
    }
    if(m >= n) {
        if(k == 1) {
            cout << 1 << '\n';
        } else if(k == 2) {
            cout << n + (m / n) - 1 << '\n';
        } else if(k == 3) {
            cout << (m - n) - m / n + 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else if(m >= 1) {
        if(k == 1) {
            cout << 1 << '\n';
        } else if(k == 2) {
            cout << m << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else cout << 0 << '\n';
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
