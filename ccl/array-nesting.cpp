//https://leetcode.com/problems/array-nesting/

class Solution {
public:
    int recur(int i, vector<int> &nums, vector<int> &vis) {
        if (vis[i]) return 0;
        
        vis[i] = 1;
        return 1 + recur(nums[i], nums, vis); 
    }
    int arrayNesting(vector<int>& nums) {
        vector<int> vis(nums.size());
        
        int ans = 0; 
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] == 0) {
                ans = max(ans, recur(i, nums, vis));
            }   
        }
        
        return ans;
    }
};