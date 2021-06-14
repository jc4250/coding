//https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i] == t) return true;
        }
        
        int ans[3] = {0,0,0};
        for (int i = 0; i < triplets.size(); i++) {
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];
            
            if ((a == t[0] || b == t[1] || c == t[2]) && a <= t[0] && b <= t[1] && c <= t[2]) {
                ans[0] = max(ans[0], a);
                ans[1] = max(ans[1], b);
                ans[2] = max(ans[2], c);
            }
            // cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        }
        
        for (int i = 0; i < 3; i++) {
            if (ans[i] != t[i]) return false;
        }
        
        return true;
    }
};