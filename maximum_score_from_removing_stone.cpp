//https://leetcode.com/problems/maximum-score-from-removing-stones/
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> vc = {a,b,c};
        sort(vc.begin(), vc.end());
        
        if (vc[0] + vc[1] <= vc[2]) {
            return vc[0] + vc[1];
        }
        
        int sum = vc[0] + vc[1];
        int ans = 0;
        
        while(sum > vc[2]) {
            ans+=1;
            sum-=2;
        }
        
        ans+=sum;
        return ans;
    }
};
