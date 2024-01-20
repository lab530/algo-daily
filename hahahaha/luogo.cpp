#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n);

//    for (int i = 0; i < n; ++i) {
//         int x;
//         cin >> x;
//         num.push_back(x);
//     }

    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    
    while(m--) {
        int  finding;

        cin >> finding;

        int j = 0, k = n - 1;
        while (j <= k) {
            int mid =  (k + j) / 2;
            if((k - j) < 2) {

            }
            // cout << mid ;
            if(finding < num[mid]) {
                k = mid - 1;
            }

            else if(finding > num[mid]) {
                j = mid + 1;
            }

            else if(finding == num[mid] ) {
                if(mid > 0 && finding == num[mid - 1]) {
                    k = mid - 1;
                }
                else {
                    cout << mid + 1<< " ";
                    break;
                }
                
            }
            //  cout << "**" << j << " " << k << endl;
        }

        if (j > k) {
            cout << "-1" << " " ;
        }
       

    }
    return 0;
}