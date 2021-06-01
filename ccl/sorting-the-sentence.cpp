//https://leetcode.com/problems/sorting-the-sentence/

class Solution {
public:
    string sortSentence(string s) {
        unordered_map<char, string> mp;
        
        stringstream ss(s);
        string word;
        
        while(ss>>word) {
            string wd = word.substr(0, word.size()-1);
            string che = word.substr(word.size()-1, word.size());
            char ch = che[0];
            mp[char(ch)] = wd+" ";
        }
        
        string ans = "";
        for (char i = '1'; i <= '9'; i++) {
            ans += mp[i];
        }
        
        return ans.substr(0, ans.size()-1);
    }
};