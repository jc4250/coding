// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution {
public:
    vector<int> ans;
    
    void recur(int i, map<int, vector<int>> &edges, int par) {
        
        ans.push_back(i);
        
        for (int j = 0; j < edges[i].size(); j++) {
            if (edges[i][j] != par) {
                recur(edges[i][j], edges, i);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjPair) {
        
        map<int, vector<int>> edges;
        
        for (int i = 0; i < adjPair.size(); i++) {
            edges[adjPair[i][0]].push_back(adjPair[i][1]);
            edges[adjPair[i][1]].push_back(adjPair[i][0]);
        }
        
        int start = 0;
        for (auto i: edges) {
            if (i.second.size() == 1) {
                start = i.first;
                break;
            }
        }
        
        recur(start, edges, 0);
        return ans;
    }
};