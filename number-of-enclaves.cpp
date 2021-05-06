//https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    vector<int> y = {-1, 0, 1, 0}, x = {0, 1, 0, -1};
    
    bool check(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return false;
        }
        return true;
    }
    
    void visitLand(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        
        for (int k = 0; k < 4; k++) {
            
            if (check(grid, i+x[k], j+y[k])) {
                visitLand(grid, i+x[k], j+y[k]);
            }
            
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        for (int i = 0; i < grid.size(); i++) {
            visitLand(grid, i, 0);
            visitLand(grid, i, grid[0].size()-1);
        }
        
        for (int i = 0; i < grid[0].size(); i++) {
            visitLand(grid, 0, i);
            visitLand(grid, grid.size()-1, i);
        }
        
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            
            for (int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j] == 1) count++;
            
            }
        }
        return count;
    }
};