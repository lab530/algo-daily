class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p = 0, q = 1;
        int ans = 0;
        int count = 0;
        while(q < n){
            
            if(nums[p] == nums[q]){
                if(count){
                    nums[q] = 0x3f3f3f3f;
                    ++ans;
                    ++q;
                }
                else{
                    ++count;
                    ++q;
                }
            }else{
                count = 0;
                p = q;
                ++q;
            }
        }
        sort(nums.begin(), nums.end());
        return n - ans;
    }
};