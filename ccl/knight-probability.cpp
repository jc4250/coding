//https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
public:
    int y[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int n;
    
    double dp[26][26][101];
    bool check(int i, int j) {
         return false;
        return true;
    }
    
    double findProbablity(int i, int j, int k) {
        if (i < 0 || j < 0 || i >= n || j >= n) return 0;
        if (k == 0) {
            return 1;
        }
        
        if (dp[i][j][k] > -1) return dp[i][j][k];
        double res = 0;
        for (int l = 0; l < 8; l++) {
            int nx = i + x[l];
            int ny = j + y[l];
            
            res += 0.125 * findProbablity(nx, ny, k-1); 
        }
        
        dp[i][j][k] = res;
        return res;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        this->n = n;
        memset(dp, -1, sizeof dp);
        return findProbablity(row, column, k);
    }
};