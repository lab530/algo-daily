class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<string, int> mag;
        for(int i = 0; i < magazine.size(); ++i) {
            mag[magazine.substr(i, 1)]++;
        }
        unordered_map<string , int> ran;
        for(int i = 0; i < ransomNote.size(); ++i) {
            ran[ransomNote.substr(i, 1)]++;
        }

        for(int i = 0; i < ransomNote.size(); ++i) {
            auto iter = mag.find(ransomNote.substr(i, 1));
            if(iter == mag.end() || iter->second < ran[ransomNote.substr(i, 1)] ) {
                return false;
            }   
        }          
    return true;       
    }
};