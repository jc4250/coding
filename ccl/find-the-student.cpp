//https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long int ans = 0;
        
        for (int i = 0; i < chalk.size(); i++) {
            ans += chalk[i];
        }
        
        if (k >= ans) {
            k %= ans;
        }
        
        
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return 1;
        
    }
};