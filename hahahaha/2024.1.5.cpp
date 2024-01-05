#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
       int n;
        cin >> n;
        vector<int>num(n);
        vector<int>ans(n);
        for(int i = 0; i < n; ++i) {
            cin >> num[i] >> ans[i] ;
        }
        vector <int> a(n);
        vector <int> b(n);

        for(int i = 0; i < n; ++i) {
            if(num[i] <= 10) {
                // a[i] = num[i];
                b[i] = ans[i];
            }
            else if (num[i] > 10) {
                // a[i] = 0;
                b[i] = 0;
            }
        }
        auto haha = max_element(b.begin(), b.end());

        for(int i = 0; i < n; ++i) {
            
            if(b[i] == *haha) {
                cout << i + 1 << endl;
            }
        }
    }
    return 0;
}