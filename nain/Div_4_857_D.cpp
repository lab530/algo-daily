#include<iostream>
#include<algorithm>
#include<cstring>
#include<numeric>
#include<functional>

using namespace std;
const int N = 2e5 + 5;
int a[N],s[N];

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i] ;
        s[i] = s[i - 1] + a[i];
    }
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        int tem = s[n] - s[r] + s[l - 1] + x * (l - r + 1); 
        puts((tem & 1 ? "YES" : "NO"));
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}