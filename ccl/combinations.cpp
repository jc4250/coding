//https://leetcode.com/problems/combinations/

class Solution {
public:
    int k, num;
    vector<vector<int>> ans;
    
    void comvo(int i, vector<int> &arr) {
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }
        
        for (int j = i; j <= num; j++) {
            arr.push_back(j);
            comvo(j+1, arr);
            arr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        num = n;
        vector<int> arr;
        comvo(1, arr);
        return ans;
    }
};