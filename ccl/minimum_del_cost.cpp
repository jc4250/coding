//https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        int maxi = 0;
        
        int i = 0;
        
        while (i < s.length()) {
            
            maxi = cost[i];
            
            int j;
            for (j = i+1; j < s.length(); j++) {
                
                if (s[i] == s[j]) {
                    ans += min(maxi, cost[j]);
                    maxi = max(maxi, cost[j]);
                } else {
                    break;
                }
            
            }
            
            i = j;
        }
        return ans;
    }
};