//https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    int count(vector<int> &arr, int check) {
        int temp = 0;
        int ans = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > check) {
                
                temp = 0;
            } else {
                
                ans += ++temp;
            }
            
        }
        
        // cout<<ans<<endl;
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left-1);
    }
};