#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1e5 + 10;
int a[N];
int b[N];

void work(){
    int n;
    cin >> n;
    memset(a, 0, N);
    bool flage = true;
    int MIN = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        MIN = min(MIN, b[i]);
        a[b[i]] ++;
        if(a[b[i]] > 1){
            flage = false;
        }
    }
    cout << ((flage && MIN == b[1]) ? "YES" : "NO") << endl;

}    


int main() {
    int t;
    cin >> t;
    while(t--)
        work();
    return 0;
}