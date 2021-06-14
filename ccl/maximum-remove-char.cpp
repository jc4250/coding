//https://leetcode.com/problems/maximum-number-of-removable-characters/

class Solution {
public:
    
    //checking str1 is subsquence of str2 or not
    bool isSubSequence(string &str1, string &str2)
    {
        int j = 0;
        
        int m = str1.length();
        int n = str2.length();
        for (int i = 0; i < n && j < m; i++)
            if (str1[j] == str2[i])
                j++;

        return (j == m);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, h = removable.size();
        int ans = 0;
        
        while (l <= h) {
            int mid = l + (h-l)/2;
            
            string arr = "";//creating new string after deletion of removable
            
            //don't know how to remove first mid element of removable from s so implemented by map
            unordered_map<int, int> mp;
            for (int i = 0; i < removable.size(), i < mid; i++) {
                mp[removable[i]] = 1;
            }
            
            for (int i = 0; i < s.length(); i++) {
                if (mp.count(i) > 0) {//checking if we have to remove or not if yes then we will skip this char
                    continue;
                }
                arr += s[i];//adding char
            }
            
            if (p.length() <= arr.length() && isSubSequence(p, arr)) {//main condition if it is subsquence then we can get answer on right side
                l = mid + 1;
                ans = mid;//storing current answer
            } else {
                h = mid - 1;
            }
        }
        
        return ans;
    }
};