#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int>num(1000), result(1000);
   
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
        }
   
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                int dis = num[0];
                result.push_back(dis);
            }
            else {
                int dis = num[i] - num[i - 1];
                result.push_back(dis);
            }
        }
        sort(result.begin(), result.end(), cmp);

        int max = result[0];
        int dis2 = (x - num[n - 1]) * 2;
        if(max >= dis2) {
            cout << max <<endl;
        }
        else if(max < dis2) {
            cout << dis2 <<endl;
        }
    }
    return 0;
}