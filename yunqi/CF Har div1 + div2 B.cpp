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
    string str;
    cin >> str;
    if(k % 2 == 0){
        sort(str.begin(), str.end());
        cout << str << endl;
    }
    else{
        vector<char> odd;
        vector<char> even;
        for(int i = 0; i < n; ++i)
        {
            if( (i + 1) % 2 != 0 ){
                odd.push_back(str[i]);
            }
            else{
                even.push_back(str[i]);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int l = 0, r = 0;
        for(int i = 0; i < n; ++i)
        {
            if( (i + 1) % 2 != 0 ){
                str[i] = odd[l];
                ++l;
            }
            else{
                str[i] = even[r];
                ++r;
            }
        }
        cout << str << endl;
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