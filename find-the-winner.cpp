//https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> arr, bnn;
        
        for (int i = 1; i <= n; i++) {
            arr.push(i);
        }
        
        while(arr.size() != 1) {
            for (int i = 1; i < k; i++) {
                int temp = arr.front();
                arr.pop();
                arr.push(temp);
            }
            arr.pop();
        }
        
        return arr.front();
    }
};

//efficient solution
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            ans = (ans+k)%i;
        }
        return ans+1;
    }
};