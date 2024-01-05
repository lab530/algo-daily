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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 1e9);
    vector<int> hrr(n + 1, 1e9);
    int minn = 1e9;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        minn = min(minn, arr[i]);
    }
    for(int i = 0; i < n; ++i){
        cin >> hrr[i];
    }
    if(minn > k){
        cout << 0 << endl;
        return;
    }
    int l = 0, r = 0;
    int ans = 0;
    i64 cnt = 0;
    while(l < n && r < n)
    {
        if(hrr[r - 1] % hrr[r] == 0 || r == l){
            cnt += arr[r];
            ++r;
        }
        else{
            cnt = arr[r];
            l = r;
            ++r;
        }
        while(cnt > k && l < r)
        {
            cnt -= arr[l];
            ++l;
        }
        ans = max(ans, r - l);
        //cout << l << ' ' << r << endl;
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