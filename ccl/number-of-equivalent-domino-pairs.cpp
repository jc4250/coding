// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dos) {
        
        map<pair<int,int>, int> mp;
        
        for (int i = 0; i < dos.size(); i++) {
            if (dos[i][0] > dos[i][1]) {
                swap(dos[i][0], dos[i][1]);
            }
            
            mp[{dos[i][0], dos[i][1]}]++;
        }
        
        int ans = 0;
        for(auto i: mp) {
            ans += (i.second-1)*(i.second)/2;
        }
        return ans;
    }
};