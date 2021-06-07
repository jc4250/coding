//https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    vector<vector<int>> arr;
    int dp[72][72][72];
    
    vector<int> dir = {1, -1, 0};
    
    bool valid(int i, int j, int k) {
        if (i >= arr.size() || j >= arr[0].size() || k >= arr[0].size() || k < 0 || j < 0) 
            return false;
        return true;
    }
    
    int dfs(int i, int j, int k) {
        if (!valid(i, j, k)) return 0;
        
        if (dp[i][j][k] != -1) return dp[i][j][k];
        
        int ans = 0;
        for (int l = 0; l < 3; l++) {
            for (int m = 0; m < 3; m++) {
                if (j + dir[l] != k + dir[m])
                    ans = max(ans, arr[i][j] + arr[i][k] + dfs(i+1, j+dir[l], k+dir[m]));
            }
        }
        return dp[i][j][k] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        arr = grid;
        
        memset(dp, -1, sizeof dp);
        
        return dfs(0, 0, grid[0].size()-1);
    }
};