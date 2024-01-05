#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b) {
    if( (a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1)){
        return a < b;
    }
    if(a % 2 == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[100];
        for(i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        if(n == 1) {
            cout << "NO";
        }
        else if(n == 2) {
            if ((arr[0] % 2 == 0 && arr[1] % 2 == 0) || (arr[0] % 2 == 1 && arr[1] % 2 == 1)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }

        }
        else {
            sort(arr, arr + n, cmp);

            if(arr[0] % 2 == 0) {
                cout << "YES" << endl;
            }

            else if (arr[n - 1] % 2 == 1 ) {
                if(n % 2 == 0){
                    cout << "YES" << endl;
                }
                else 
                    cout << "NO" << endl;
            }

            else{
                int check = 0;
                for(i = 0; i < n; ++i) {
                    if(arr[i] % 2 == 0) {
                        if(i % 2 == 0) {
                            check++;
                            break;
                        }
                        break;
                    }
                }

                if(check == 1) {
                    cout << "YES" << endl;
                }

                else if (check == 0) {
                    cout <<"NO" << endl;
                }
            }
        }
    }
    return 0;
}