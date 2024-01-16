#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        string str;
        cin >> str;
        unordered_map<char, int> mp;

        for(auto haha : mp) {
            cout << haha.first << "->" << haha.second << endl;
        }

        for(int i = 0; i < num; ++i) {
            mp[str[i]]++;
        }
        // for(auto v: mp) {
        //     cout << v.first << " " << v.second << endl;
        // } 
        // for(int i = 0; i < num; ++i) {
        //     cout <<  mp[str[i]] << " " ;
        // }
        
        // cout << endl;

        int sum = 0;

        for(auto iter = mp.begin(); iter != mp.end(); iter++) {
            int a = iter->first - 64;
            if(iter != mp.end() && iter->second >= a) {
                sum++;
            }
            // auto xixi = mp.find(str[i]);
            // if(xixi != mp.end()) {
            //     int a = xixi->first - 64;
            //     cout  << xixi->second << " "<< a <<endl;
            //     if(xixi->second >= a) {
            //         sum++;
            //     }
            // }
           
        }
        // for(int i = 0; i < num; ++i) {
        //     int  b = str[i];
        //     cout << b << " " ;
        //     int a = str[i] - 64;
        //     if(mp[str[i]] >= a) {
        //         sum++;
        //     }
        // }

        cout << sum << endl;
    }
    return 0;
}