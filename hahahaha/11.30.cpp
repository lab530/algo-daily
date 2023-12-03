#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>number(n);
    set<int>sum;
    for(int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    sort(number.begin(),number.end());

    for(int i = 0; i < n; ++i) {
        int a = number[i];
        sum.insert(a);
    }

    cout << sum.size() << endl;
    for(auto i = sum.begin(); i != sum.end(); ++i) {
        cout  << *i << " ";
    }

    return 0;
}