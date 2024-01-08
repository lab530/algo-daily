
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> ab;
        for(int i = 0; i < nums1.size(); ++i) {
            for(int j = 0; j < nums2.size(); ++j) {
                ab[nums1[i] + nums2[j]]++;
            }
        }
      
        int sum = 0; 
        for(int C: nums3) {
            for(int D: nums4) {
                int xixi = 0 - (C + D);
                auto haha = ab.find(xixi);
                if(haha != ab.end()) {
                    sum +=  haha->second;
                }
            }
        }
        return sum;
    }
};