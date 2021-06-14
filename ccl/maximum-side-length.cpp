//https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/


class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        vector<vector<int>> arr(305, vector<int> (305, 0));
        
        for (int i = 0; i < mat[0].size(); i++) {
            arr[1][i+1] += mat[0][i];
            if(i == 0) continue;
            arr[1][i+1] += arr[1][i];
        }
        

        arr[1][1] = 0;
        for (int i = 0; i < mat.size(); i++) {
            arr[i+1][1] += mat[i][0];
            if (i == 0) continue;
            
            arr[i+1][1] += arr[i][1];
        }
        
        for (int i = 1; i < mat.size(); i++) {
            
            for (int j = 1; j < mat[0].size(); j++) {
                
                arr[i+1][j+1] = mat[i][j] + arr[i][j+1] + arr[i+1][j] - arr[i][j];
            }
        }

        int ans = 0;
        int l = 1, h = min(mat.size(), mat[0].size());
        
        while (l <= h) {
            
            int mid = l + (h - l)/2;
            
            int flag = 0;
            
            for (int i = mid; i <= mat.size(); i++) {
                for (int j = mid; j <= mat[0].size(); j++) {
                    
                    if (arr[i][j] - arr[i-mid][j] - arr[i][j-mid] + arr[i-mid][j-mid] <= threshold) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }

            if (flag) {
                l = mid+1;
                ans = mid;
            } else {
                h = mid-1;
            }
        }
        return ans;
    }
};