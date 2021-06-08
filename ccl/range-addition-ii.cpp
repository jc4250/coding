//https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = INT_MAX, y = INT_MAX;
        
        if (ops.size() == 0) return m*n;
        
        for (int i = 0; i < ops.size(); i++) {
            x = min(x, ops[i][0]);
            y = min(y, ops[i][1]);
        }
        
        return x*y;
    }
};