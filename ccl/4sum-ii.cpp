//https://leetcode.com/problems/4sum-ii/

class Solution {
public:

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        
        int ans = 0;
        
        unordered_map<long long int, int> arr;
        for (int i = 0; i < nums4.size(); i++) {
            for (int j = 0; j < nums3.size(); j++) {
                arr[nums4[i]+nums3[j]]++;
            }
        }
        
        
        for (int i = 0; i < nums1.size(); i++) {
            
            for (int j = 0; j < nums2.size(); j++) {
                    
                    long long int total = nums1[i] + nums2[j];
                    long long int rem = -1 * total;
                
                    auto it = arr.find(rem);
                    if(it != arr.end()) {
                        ans += it->second;
                    }
            }
        }
        return ans;
    }
};