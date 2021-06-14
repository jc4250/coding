//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        
        int l = 1, h = 1e9;
        int rans = -1;
        while(l <= h) {
            long int mid = l + (h - l)/2;
            
            int temp = 0, ans = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] <= mid) {
                    temp++;
                } else {
                    temp = 0;
                }
                
                if (temp >= k) {
                    temp = 0;
                    ans++;
                }
            }
            
            if (ans >= m) {
                h = mid - 1;
                rans = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return rans;
    }
};