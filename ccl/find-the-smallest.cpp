//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
     
        int ans = 0;
        
        // long int sum = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     sum += nums[i];
        // }
        
        int l = 1, h = 1e6;
        while (l <= h) {
            int mid = l + (h - l)/2;
            
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                
                sum += ceil(1.0*nums[i]/mid);
            }
            
            if (sum <= threshold) {
                h = mid -1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};