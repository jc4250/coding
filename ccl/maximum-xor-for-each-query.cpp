//https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mBit) {
        vector<int> ans;
        
        int allxor = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            allxor ^= nums[i];
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            int temp = 0;
            for (int k = 0; k < mBit; k++) {
                bool isset = (1<<k) & allxor;
                
                if (!isset) {
                    temp ^= (1<<k); 
                }
            }
            
            ans.push_back(temp);
            allxor ^= nums[i];
        }
        
        return ans;
    }
};