class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k , n);
        for(int start = 0; start < count; ++start){
            int prev = nums[start];
            int current = start;
            do{
                int next = (current + k) % n;
                swap(prev, nums[next]);
                current = next;
            }while(start != current);
        }
        
    }
};