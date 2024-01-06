class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mp;
        int sum = 0;

        mp.insert(make_pair("I", 1));
        mp.insert(make_pair("V", 5));
        mp.insert(make_pair("X", 10));
        mp.insert(make_pair("L", 50));
        mp.insert(make_pair("C", 100));
        mp.insert(make_pair("D", 500));
        mp.insert(make_pair("M", 1000));

        for (int i = 0; i < s.size(); ++i) {
            auto iter = mp.find(s.substr(i, 1));
            if (i + 1 < s.size()) {  
                auto haha = mp.find(s.substr(i + 1, 1));
                    if (iter->second < haha->second) {
                        sum = sum + haha->second - iter->second;
                        i++;  
                    } 
                    else {
                        sum = sum + iter->second;
                    }
                }
            else {
                sum = sum + iter->second;
            }
        }
        return sum;
    }
};