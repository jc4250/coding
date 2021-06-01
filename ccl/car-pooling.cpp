//https://leetcode.com/problems/car-pooling/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        vector<int> arr(1001);
        
        for (int i = 0; i < trips.size(); i++) {
            arr[trips[i][1]] += trips[i][0];
            arr[trips[i][2]] -= trips[i][0];
        }
        
        int maxi = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) {
                arr[i] += arr[i-1];
                maxi = max(maxi, arr[i]);
            }
        }
        
        return maxi<=cap;
    }
};