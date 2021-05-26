//https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                int temp = abs(nums[i-1] - nums[i]) + 1;
                ans += temp;
                nums[i] += temp;
            }    
        }
        
        return ans;
    }
};