//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution {
public:
    int maxValue(int n, int ind, int maxSum) {
        int high = maxSum, low = 1;
        long long int sum = 0;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low)/2;
            
            long long int total = 1LL * mid * (mid + 1)/2;
            long long int left, right;
            
            if (mid <= ind) {
                left = total + ind - mid + 1;
            } else {
                left = 1LL*(mid - ind - 1) * (mid - ind)/2;
                left = total - left;
            }
            
            int rr = n-ind-1;
            if (mid <= rr) {
                right = total + rr - mid + 1;
            } else {
                right = 1LL*(mid - rr - 1) * (mid - rr)/2;
                right = total - right;
            }
            
            if (left + right - mid <= maxSum) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            
            
        }
        
        return ans;
    }
};