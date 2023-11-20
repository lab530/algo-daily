class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size();
        int left = 0;
        while(left < right){
            if(nums[left] == val){
                nums[left] = nums[right - 1];
                --right;
            }else{
                ++left;
            }
        }
        return left;
    }
};