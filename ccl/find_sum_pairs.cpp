//https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs {
public:
    unordered_map<int, int> mp, mp1;
    vector<int> arr1, arr2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]]++;
        }
        for (int i = 0; i < nums1.size(); i++) {
            mp1[nums1[i]]++;
        }
    }
    
    void add(int ind, int val) {
        mp[arr2[ind]]--;
        int temp = arr2[ind] + val;
        arr2[ind] = temp; 
        mp[temp]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto i: mp1) {
            if(mp.count(tot-(i.first)) > 0) {
                ans+= i.second* mp[tot-(i.first)];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */