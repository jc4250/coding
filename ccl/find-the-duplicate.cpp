//https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int l = 1, h = nums.size();
        
        while(l < h) {
            int mid = l + (h-l)/2;
            
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }
            
            if (count <= mid) {
                l = mid+1;
            } else {
                h = mid;
            }
        }
        
        return l;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        
        
        return slow;
    }
};