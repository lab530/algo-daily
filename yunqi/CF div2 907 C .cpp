#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<climits>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    i64 summ = 0;
    vector<i64> arr(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        summ += arr[i];
    }
    sort(arr.begin(), arr.end());
    i64 ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += arr[i];
        if(ans == (summ + 1) / 2){
            cout << ans + n - 1 - i << endl;
            break;
        }
        else if(ans * 2 > summ + 1){
            cout << (summ + 1) / 2 + n - i << endl;
            break;
        }
    }
    
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}