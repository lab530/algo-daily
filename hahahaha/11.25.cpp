
#include <iostream>
using namespace std;
int main() {
    int t;
    int s[1000], e[1000];
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s[i] >> e[i];
        }
        
        int a = true;
        for (int i = 1; i < n; ++i) { 
            if (s[i] >= s[0] && e[i] >= e[0]) {
                a = false;
            }
        }
            
        if (a != true) {
            cout << "-1" << endl;
            continue;
        }
        
        cout << s[0] << endl;
    }
    return 0;
}