//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

class Solution {
public:
    int rswap(string s, char cur) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!(i&1) && s[i] != cur) {
                ans++;
            }
        }
        return ans;
    }
    
    int dswap(string s) {
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!(i&1) && s[i] != '1') {
                ans++;
            }
        }
        temp = ans;
        ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i&1) && s[i] != '1') {
                ans++;
            }
        }
        
        temp = min(temp, ans);
        return temp;
    }
    
    int minSwaps(string s) {
        int len = s.length();
        int one = 0, zero;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') one++;
        }
        
        zero = len - one;
        if (abs(one - zero) > 1) return -1;
        
        int ans = INT_MAX;
        if (one > zero) {
            ans = min(ans, rswap(s, '1'));
        }
        if (zero > one) {
            ans = min(ans, rswap(s, '0'));
        }
        if (zero == one) {
            ans = min(ans, dswap(s));
        }
        return ans;
    }
};