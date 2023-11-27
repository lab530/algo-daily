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

int arr[1000005];
int n, x;

bool check(i64 mid)
{
    i64 cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= mid) break;
        cnt += mid - arr[i];
    }
    //cout << cnt << endl;
    if(cnt <= x) return true;
    else return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        i64 l = 0, r = arr[n - 1] + x;
        while(l < r)
        {
            i64 mid = (l + r + 1) / 2;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}