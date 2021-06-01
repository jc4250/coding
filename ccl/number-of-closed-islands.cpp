//https://leetcode.com/problems/number-of-closed-islands/
class Solution {
public:
    vector<int> y = {1, 0, -1, 0}, x = {0, 1, 0, -1};
    
    bool valid(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return false;
        }
        return true;
    }
    
    void fill(vector<vector<int>> &grid, int i, int j) {
        
        if (grid[i][j] == 0) {
            
            grid[i][j] = 1;
            
            for (int k = 0; k < 4; k++) {
                
                if (valid(grid, i+x[k], j+y[k])) {
                    
                    fill(grid, i+x[k], j+y[k]);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        for (int i = 0; i < grid.size(); i++) {
            
            for (int j = 0; j < grid[0].size(); j++) {
                
                if (i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1) {
                    fill(grid, i, j);
                }
                
            }
            
        }
        
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            
            for (int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j] == 0) {
                    ans++;
                    fill(grid, i, j);
                }
                
            }
            
        }
        
        return ans;
    }
};