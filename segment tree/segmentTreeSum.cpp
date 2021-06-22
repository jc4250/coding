//https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    vector<int> arr;
    vector<int> num;
    
    void buildSegTree(int si, int ss, int se) {
        if (ss == se) {
            arr[si] = num[ss];
        } else {
            int mid = (ss + se) / 2;
            
            buildSegTree(2 * si, ss, mid);
            buildSegTree(2 * si + 1, mid + 1, se);
            
            arr[si] = arr[si * 2] + arr[si * 2 + 1];
        }
    }
    
    int querySegTree(int si, int ss, int se, int qs, int qe) {
        if (qs > se || qe < ss) {
            return 0;
        }
        
        if (qs <= ss && se <= qe) {
            return arr[si];
        }
        
        int mid = ss + (se - ss)/2;
        int left = querySegTree(2 * si, ss, mid, qs, qe);
        int right = querySegTree(2 * si+1, mid+1, se, qs, qe);
        
        return left + right;
    }
    
    void updateSegTree(int si, int ss, int se, int q) {
        
        if (ss == se) {
            arr[si] = num[ss];
            // return;
        } else {
            
            int mid = ss + (se - ss)/2;
            
            if (q <= mid) updateSegTree(si*2, ss, mid, q);
            else updateSegTree(si*2+1, mid+1, se, q);
            
            arr[si] = arr[si*2] + arr[si*2 + 1];
        }
    }
    
    
    
    NumArray(vector<int>& nums) {
        arr = vector<int> (4 * nums.size());
        num = nums;
        buildSegTree(1, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        num[index] = val;
        updateSegTree(1, 0, num.size()-1, index);
    }
    
    int sumRange(int left, int right) {
        
        // for (int i = 0; i < num.size() * 3; i++) {
        //     cout<<i<<" "<<arr[i]<<endl;
        // }
        return querySegTree(1, 0, num.size()-1, left, right);
    }
};