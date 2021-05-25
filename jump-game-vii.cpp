//https://leetcode.com/problems/jump-game-vii/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> dp(s.length());
        int pre = 0;
        dp[0] = 1;
        
        for (int i = 1; i < s.length(); i++) {
            
            if (i >= minJump) {
                pre += dp[i - minJump];
            }
            
            if (i > maxJump) {
                pre -= dp[i - maxJump - 1];
            }
            
            dp[i] = pre > 0 && s[i] == '0';
        }
        
        return dp[s.length()-1];
    }
};

//recursion
class Solution {
public:
    int minj = 0;
    int maxj = 0;
    int ans = 0;
    int len = 0;
    vector<int> arr;
    vector<int> zeros;
    
    void recur (int i) {
        if (i >= len) {
            ans = 1;
        }
        
        if (arr[i]) return;
        
        arr[i] = 1;
        int left = i+maxj;
        left = min(left, len);
        
        for (int j = i+minj ; j <= left; j++) {
            if (ans == 1) {
                break;
            }
            if (arr[j] != 0) break;
            
            if (zeros[j] && ans == 0) {
                recur(j);
            }
        }
    }
    
    bool canReach(string s, int minJump, int maxJump) {
        minj = minJump;
        maxj = maxJump;
        len = s.length() - 1;
        zeros = vector<int>(s.size(), 0);
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '0') {
                zeros[i] = 1;
            }
        }
        
        arr = vector<int> (len+1);
        recur(0);
        
        return ans;
    }
};