#include<iostream>

using namespace std;

int dfs(int n ,int x){
    if(n == x){
        return 1;
    }

    if(n % 3 == 0){
        if(n / 3 == x || 2 * n / 3 == x){
            return 1;        
        }
        else {
            return dfs(n / 3 , x)||dfs(2 * n / 3 , x);
        }
    }
    return 0;       
}


void solve(){
    int n,x;
    cin >> n >> x;
    int ans = dfs(n,x);
    if(ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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