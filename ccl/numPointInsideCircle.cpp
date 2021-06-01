//https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (int i = 0; i < queries.size(); i++) {
            
            int temp = 0;
            for (int j = 0; j < points.size(); j++) {
            int mul = (queries[i][0] - points[j][0]) * (queries[i][0] - points[j][0]) + (queries[i][1] - points[j][1]) * (queries[i][1] - points[j][1]);
                // int r = sqrt(mul);
                
                // cout<<i<<" "<<j<<" "<<mul<<endl;
                if (mul <= queries[i][2]*queries[i][2]) {
                    temp++;
                }
            }
            
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};