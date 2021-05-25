//https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        long long int high = INT_MAX;
        long long int low = 1;
        
        
        double ans = 0;
        
        long long int gans = INT_MAX;
        while (low <= high) {
            long long int mid = (low) + (high - low) / 2;
            
            ans = 0;
            for (int i = 0; i < dist.size()-1; i++) {
                ans += ceil((dist[i]*1.0)/mid);
            }
            
            ans += ((dist[dist.size()-1]*1.0)/mid);
            
            if (hour >= ans) {
                gans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (gans == INT_MAX) return -1;
        return gans;
    }
};