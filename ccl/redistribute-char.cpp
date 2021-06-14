//https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> arr(26);
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                arr[words[i][j]-'a']++;
            }
        }
        
        int stat = 0;
        int n = words.size();
        for (int i = 0; i < 26; i++) {
            if (arr[i] % n != 0) return false;
        }
        
        return true;
    }
};