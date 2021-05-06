//https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        int maxi = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i-1]) > 1) {
                maxi++;
                arr[i] = maxi;
            } else {
                maxi = max(maxi, arr[i]);
            }
        }
        return maxi;
    }
};