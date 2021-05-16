//https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> arr(nums.begin(), nums.end());
        
        if (k == 1) return true;
        int temp = k;
        auto fir = arr.begin();
        
        while (!arr.empty()) {

            auto it = arr.find(*fir+1);
            if (it != arr.end()) {
                arr.erase(fir);
                fir = it;
                temp--;
            } else {
                return false;
            }
            
            if (temp == 1 && !arr.empty()) {
                arr.erase(fir);
                fir = arr.begin();
                temp = k;
            }
        }
        return true;
    }
};