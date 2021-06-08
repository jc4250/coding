//https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    
    vector<vector<int>> arr;
    
    int searchString(int curr, int i) {
        int low = 0, high = arr[i].size()-1;
        
        int ans = -1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            
            if (arr[i][mid] > curr) {
                high = mid-1;
                ans = arr[i][mid];
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        arr = vector<vector<int>> (26);
        for (int i = 0; i < s.length(); i++) {
            arr[s[i]-'a'].push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            int temp = -1;
            for (int j = 0; j < words[i].length(); j++) {
                temp = searchString(temp, words[i][j]-'a');
                if (temp == -1) break;
            }
            
            if (temp != -1) {
                ans++;
            }
        }
        
        return ans;
    }
};