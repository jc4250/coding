//https://leetcode.com/problems/rotating-the-box/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> arr(box[0].size(), vector<char> (box.size()));
        
        
        for (int i = 0; i < box.size(); i++) {
            int stone = 0;
            
            for (int j = 0; j < box[0].size(); j++) {
                
                if (box[i][j] == '*') {
                    
                    arr[j][i] = '*';
                    
                    for (int k = 0; k < stone; k++) {
                        arr[j-k-1][i] = '#';
                    }
                    
                    stone = 0;
                } else {
                    arr[j][i] = '.';
                }
                
                if (box[i][j] == '#') stone++;
                
            }
            
            for (int k = 0; k < stone; k++) {
                arr[box[0].size()-k-1][i] = '#';
            }
        }
        
        for (int i = 0; i < box[0].size(); i++) {
            reverse(arr[i].begin(), arr[i].end());
        }
        
        return arr;
        
    }
};