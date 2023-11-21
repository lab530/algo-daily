#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s[21];
int n;
bool cmp(const string &a,const string &b) {
    return (a+b > b+a);
}
int main() {
    cin >> n;
    for(int i=1;i<=n;++i) cin >> s[i];
    sort(s+1,s+n+1,cmp);
    for (int i=1;i<=n;++i) cout << s[i];
    return 0;
}