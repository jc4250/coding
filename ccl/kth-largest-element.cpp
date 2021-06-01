//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int k;
    int partition(vector<int> &arr, int l, int r) {
        int pivot = arr[l];

        int i = l;
        int j = r+1;

        while(i < j) {

            while (i < r && pivot >= arr[++i]);

            while (j > l && pivot < arr[--j]);

            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[j]);
        return j;
    }

    void quicksort(vector<int> &arr, int l, int r) {

        if (l < r) {
            int mid = partition(arr, l, r);
            // cout<<mid<<endl;
            if (mid > k) {
                
                quicksort(arr, l, mid-1);
            } else if (mid < k) {
                
                quicksort(arr, mid+1, r);
            } else {
                return;
            }
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
       
        //bubble sort
        // for (int i = 0; i < k; i++) {
        //     for (int j = 0; j < nums.size() - i -1; j++) {
        //         if (nums[j] > nums[j+1]) {
        //             nums[j] += nums[j+1];
        //             nums[j+1] = nums[j] - nums[j+1];
        //             nums[j] = nums[j] - nums[j+1];
        //         }
        //     }
        // }
        
        this->k = nums.size() - k;
        quicksort(nums, 0, nums.size()-1);
        return nums[nums.size()-k];
    }
};