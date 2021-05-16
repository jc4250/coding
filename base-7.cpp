//https://leetcode.com/problems/base-7/

class Solution {
public:
    string recur(int num) {
        if (num < 7) {
            return to_string(num);
        }
        
        int rem = num % 7;
        return recur(num/7) + to_string(rem);
    }
    
    string convertToBase7(int num) {
        if (num < 0) {
            return '-'+ recur(-1*num);
        }
        return recur(num);
    }
};