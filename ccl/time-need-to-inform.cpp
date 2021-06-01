//https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    int getMaxTime(int i, vector<vector<pair<int, int>>> &arr) {
        if (arr[i].size() == 0) return 0;
        
        int ans = 0;
        
        for (int j = 0; j < arr[i].size(); j++) {
            int lc = arr[i][j].second + getMaxTime(arr[i][j].first, arr);
            ans = max(ans, lc);
        }
        
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& time) {
        vector<vector<pair<int, int>>> arr(n);
        
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            
            arr[man[i]].push_back(make_pair(i, time[i]));
        }
        
        return time[headID] + getMaxTime(headID, arr);
    }
};