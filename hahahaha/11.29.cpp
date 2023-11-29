#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
   
    int num;

    for(int i = 0; i < n; ++i) {
        cin >> num;
        arr[i] = abs(num - 0);
    }

    sort(arr.begin(), arr.end());

    if (arr[0] == 0) {
        cout << "0" << endl;
    }
    
    else if(arr[0] != 0) {
        for(int i = 0; i < n; ++i) {
            if(arr[i] != 0) {
                int result = arr[i];
                cout << result << endl;
                break;
            }
        }
    }
    
    return 0;
}