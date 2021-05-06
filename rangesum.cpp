//https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    const int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pre;
        
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (i == 0) {
                    pre.push_back(nums[j]);
                } else {
                    pre.push_back(nums[j] - nums[i-1]);
                }
            }
        }
        
        sort(pre.begin(), pre.end());

        int ans = 0;
        for (int i = left-1; i < right; i++) {
            
            ans = (ans+pre[i]) % MOD;
        }
        return ans;
    }
};