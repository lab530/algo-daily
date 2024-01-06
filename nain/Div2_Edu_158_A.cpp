#include<iostream>

using namespace std;
const int N = 1e2 + 10;
int a[N]; 

void solve(){
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ans = max(ans, a[i] - a[i - 1]);
    }
    ans = max(ans, (x - a[n])*2);
    cout << ans << endl;
}

int main(){
    int t ;
    cin >> t ;
    while(t --){
        solve();
    }
}