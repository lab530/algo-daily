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
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    i64 ans = 0;
    i64 minn = 1e12;
    for(int i = n; i > 0; --i)
    {
        if(arr[i] <= minn){
            minn = arr[i];
        }
        else{
            int t = (arr[i] + minn - 1) / minn;
            ans += t - 1;
            minn = arr[i] / t;
        }
    }
    cout << ans << endl;
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