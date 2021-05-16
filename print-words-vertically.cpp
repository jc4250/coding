// https://leetcode.com/problems/print-words-vertically/

class Solution {
public:
    
    const std::string WHITESPACE = " \n\r\t\f\v";
    
    std::string rtrim(const std::string &s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }
    
    vector<string> printVertically(string s) {
        vector<string> arr, ans;
        
        stringstream ss(s);
        string word;
        int len = 0;
        while(ss>>word) {
            int l = word.length();
            len = max(len, l);
            arr.push_back(word);
        }
        
        
        for (int i = 0; i < len; i++) {
            string lc = "";
            for (int j = 0; j < arr.size(); j++) {
                if (i <= arr[j].length() - 1) {
                    lc+=arr[j][i];
                } else {
                    lc+=' ';
                }
            }
            // cout<<lc<<endl;
            ans.push_back(rtrim(lc));
        }
        return ans;
    }
};