
https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double agm = (1.0 * 360 * minutes)/(60);
        
        double orh = ((1.0 * minutes)/(60)) + hour;
        
        if (orh >= 12) {
            orh -= 12;
        }
        
        double agh = (1.0 * 30 * orh);
        
        return min(abs(agm-agh), 360 - abs(agm-agh));
    }
};
