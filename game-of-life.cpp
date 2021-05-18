//https://leetcode.com/problems/game-of-life/

class Solution {
public:
    vector<int> x = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> y = {1, 1, 0, -1, -1, -1, 0, 1};
    
    bool check(vector<vector<int>> &arr, int i, int j) {
        if (i >= arr.size() || j >= arr[0].size() || i < 0 || j < 0) return false;
        return true;
    } 
    
    void gameOfLife(vector<vector<int>>& board) {
        
        for (int i = 0; i < board.size(); i++) {
            
            for (int j = 0; j < board[i].size(); j++) {
                
                int temp = 0;
                
                for (int k = 0; k < 8; k++) {
                    if (check(board, i+x[k], j+y[k])) {
                        if (abs(board[i+x[k]][j+y[k]]) == 1) {
                            temp++;
                        }
                    }
                }
                
                if (temp < 2) {
                    if (board[i][j] == 1) board[i][j] = -1;
                }
                
                if (temp == 3) {
                    if (board[i][j] == 0) board[i][j] = 2;
                }
                
                if (temp > 3) {
                    if (board[i][j] == 1) board[i][j] = -1;
                }
            }
            
        }
        
        for (int i = 0; i < board.size(); i++) {
            
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                }
            }
        }
    }
};