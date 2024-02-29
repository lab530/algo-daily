class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int mod = k % len;
        vector<int> arr(len * 2);
        for(int i = 0; i < len * 2; ++i){
            if(i >= len){
                arr[i] = nums[i -len];
            }
            else arr[i] = nums[i];
        }
        for(int i = 0; i < len; ++i){
            nums[i] = arr[len - mod];
            mod--;
        }
    }
};