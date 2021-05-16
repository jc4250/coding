//https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (vector<int> a, vector<int> b) {
            if (a[0] < b[0]) return true;
            if (a[0] > b[0]) return false;
            
            if (a[1] > b[1]) return true;
            return false;
        });
        
        
        int ans = 0;
        
        for (int i = 0; i < intervals.size(); i) {
            
            int j = 0;
            for (j = i+1; j < intervals.size(); j++) {
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                    ans++;
                    continue;
                } else {
                    break;
                }
            }
            i = j;
        }
        return intervals.size()-ans;
    }
};