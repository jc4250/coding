//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>> &arr) {
        if (vis[i]) return;
        vis[i] = 1;
        
        for (int j = 0; j < arr[i].size(); j++) {
            if (!vis[arr[i][j]]) {
                dfs(arr[i][j], vis, arr);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<vector<int>> arr(n);
        vector<int> vis(n);
        
        if (con.size() < n-1) return -1;
        for (int i = 0; i < con.size(); i++) {
            arr[con[i][0]].push_back(con[i][1]);
            arr[con[i][1]].push_back(con[i][0]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, vis, arr);
            }
        }
        
        return ans-1;
    }
};