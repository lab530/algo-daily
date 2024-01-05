#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int nums[n + 1];
    long long int sum = 0;
    for (int i = 0; i < n; ++i){
        cin >> nums[i];
        sum += nums[i];
    }
    long long int L, R;
    cin >> L >> R;
    if(sum < n*L || sum > n*R) cout << "-1" <<endl;
    else{
        int min1 = 0;
        int max1 = 0;
        for (int i = 0; i < n; ++i){
            if(nums[i] > R) max1 += nums[i] - R;
            if(nums[i] < L) min1 += L - nums[i];
        }
        cout <<  (max1 > min1 ? max1 : min1) << endl;
    }

    return 0;
}