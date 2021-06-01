//https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:
    int ans = 0;
    void recur(vector<int> &nums, int i, int flg, int lc) {
        if(flg) ans+=lc;
        if (i >= nums.size()) return;
        
        recur(nums, i+1, 1,lc^nums[i]);
        recur(nums, i+1, 0,lc);
    }
    int subsetXORSum(vector<int>& nums) {
        int lc = 0;
        recur(nums, 0, 0, lc);
        return ans;
    }
};