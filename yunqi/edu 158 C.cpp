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

i64 check(i64 a, i64 b)
{
    i64 ans = 0;
    while (a != b)
    {
        b = (a + b) / 2;
        ans++;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    else{
        sort(arr.begin(), arr.end());
        i64 maxx = 0, cnt = arr[0];
        maxx = check(arr[0], arr[n - 1]);
        cout << maxx << endl;
        if(maxx <= n){
            while(maxx--){
                cout << cnt << ' ';
            }    
        }
        cout << endl;
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