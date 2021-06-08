//https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> arr;
        map<string, int> freq;
        
        for (int i = 0; i < list1.size(); i++) {
            freq[list1[i]]++;
            arr[list1[i]] = i;
        }
        
        for (int i = 0; i < list2.size(); i++) {
            freq[list2[i]]++;
            arr[list2[i]] += i;
        }
        
        
        int temp = INT_MAX;
        vector<string> ans;
        
        for (auto i: arr) {
            // cout<<i.first<<" "<<i.second<<endl;
            // cout<<freq[i.first]
            if (freq[i.first] > 1) {
                // cout<<i.first<<endl;
                if (temp == i.second) {
                    ans.push_back(i.first);
                }
                
                if (temp > i.second) {
                    ans.clear();
                    ans.push_back(i.first);
                    temp = i.second;
                }
                
            }
        }
        
        return ans;
    }
};