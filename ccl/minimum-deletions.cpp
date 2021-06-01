//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> arr(26);
        
        for (int i = 0; i < s.length(); i++) {
            arr[s[i]-'a']++;
        }
        
        unordered_map<int, int> mp;
        int ans = 0;
        
        for (int i = 0; i < 26; i++) {
            if (mp.count(arr[i]) >= 1) {
                
                for (int j = 0; j < 26; j++) {
                    if (arr[i]-j == 0) {
                        ans+=j;
                        break;
                    }
                    if (mp.count(arr[i]-j) == 0) {
                        ans += j;
                        mp[arr[i]-j] = 1;
                        break;
                    }
                }
            } else {
                mp[arr[i]] = 1;
            }
        }
        return ans;
    }
};