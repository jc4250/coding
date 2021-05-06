//https://leetcode.com/problems/rearrange-words-in-a-sentence/

class Solution {
public:
    string arrangeWords(string str) {
        str[0] = tolower(str[0]);
        stringstream ss(str), res;
        
        string word;
        
        map<int, string> mp;
        while (ss>>word) {
            int len = word.length();
            mp[len] += (word+" ");
        }
        
        string ans = "";
        
        for (auto &i: mp) {
           res<<i.second;
        }
        
        ans = res.str();
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        
        return ans;
    }
};