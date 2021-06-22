//https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    int y[4] = {1, 0, -1, 0};
    int x[4] = {0, 1, 0, -1};
    
    void dfs(int i, int j, vector<vector<int>> &grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        
        if (grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            dfs(i+x[k], j + y[k], grid);
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1 && grid1[i][j] == 0) {
                    dfs(i, j, grid2);
                }
            }    
        }
        
        int ans = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    dfs(i, j, grid2);
                    ans++;
                }
            }    
        }
        
        return ans;
    }
};