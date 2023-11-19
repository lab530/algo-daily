class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int fast = 0, slow = 0, ans = 0, max_length = 0;
        while(fast < len)
        {
            if(nums[fast] != nums[slow]){
                if(fast - slow > max_length && fast - slow > len / 2){
                    max_length = fast - slow;
                    ans = nums[slow];
                }
                slow = fast;
            }
            else if(fast == len - 1){
                if(fast - slow + 1 > max_length && fast - slow + 1 > len / 2){
                    max_length = fast - slow;
                    ans = nums[slow];
                }
            }
            fast++;
        }
        return ans;
    }
};