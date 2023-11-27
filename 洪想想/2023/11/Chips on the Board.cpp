#include<bits/stdc++.h>
using namespace std;
 void slove(){
    int n;
    cin >> n;
    long long sa = 0;
    int mina=INT_MAX;
    int minb = INT_MAX;
    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        sa += a;
        mina = min(mina, a);
    }

    long long sb = 0;
    for(int i = 1; i <= n; i++){
        int b;
        cin >> b;
        sb += b;
        minb = min(minb, b);
    }
    long long ans = min(sa + 1LL * n * minb, sb + 1LL * n * mina);
    cout<<ans<<endl;

}
int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        slove();
    }
    return 0;
}