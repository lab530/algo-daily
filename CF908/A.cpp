#include<iostream>

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(s[n-1] == 'A'){
        cout << 'A' << endl;
    }
    else{
        cout << 'B' << endl;
    }
}

int main(){
    int t ;
    cin >> t ;
    while(t --){
        solve();
    }
}