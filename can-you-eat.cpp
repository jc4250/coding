//https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

class Solution {
public:
    vector<bool> canEat(vector<int>& candCount, vector<vector<int>>& queries) {
        vector<long long int> arr(candCount.size());
        
        arr[0] = candCount[0];
        for (int i = 1; i < candCount.size(); i++) {
            arr[i] = candCount[i];
            arr[i] += arr[i-1];
        }
        
        vector<bool> ans;
        
        for (int i = 0; i < queries.size(); i++) {
            if (arr[queries[i][0]] >= queries[i][1]+1) {
                if (queries[i][0] == 0) {
                    ans.push_back(true);
                } else {
                    long long int temp = arr[queries[i][0] - 1];
                    if (temp < 1LL*(queries[i][1]+1) * queries[i][2]) {
                        ans.push_back(true);
                    } else {
                        ans.push_back(false);
                    }
                }
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};