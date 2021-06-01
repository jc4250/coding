// https://leetcode.com/problems/maximum-number-of-balls-in-a-box/

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> mp;
        
        for (int i = lowLimit; i <= highLimit; i++) {
            int temp = i;
            
            int ans = 0;
            while (temp > 0) {
                ans += temp % 10;
                temp /= 10;
            }
            
            mp[ans]++;
        }
        
        int ans = 0;
        for (auto i: mp) {
            ans = max(ans, i.second);
        }
        return ans;
    }
};