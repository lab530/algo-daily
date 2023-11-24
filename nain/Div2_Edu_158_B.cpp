#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N], b[N]; 

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ans = a[0] - 1;
    for(int i = 0; i < n - 1; ++i){
        if(a[i] < a[i + 1]){
            ans += a[i + 1] - a[i];
        }
    }
    cout << ans << endl;

}

int main(){
    int t ;
    cin >> t ;
    while(t --){
        solve();
    }
}