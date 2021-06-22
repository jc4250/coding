//https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int dp[50005][3];
    int solve(int i, vector<int> &arr, int ans) {
        
        if (i >= arr.size()) {
            if (ans % 3 == 0) return 0;
            return INT_MIN;
        }
        
        if (dp[i][ans]) return dp[i][ans];
        
        return dp[i][ans%3] =max(arr[i] + solve(i+1, arr, (ans+arr[i])%3), solve(i+1, arr, ans));
    }
    int maxSumDivThree(vector<int>& nums) {
        return solve(0, nums, 0);
    }
};