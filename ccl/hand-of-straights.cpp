//https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int, int> mp;
        
        for (int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;
        }
        
        for (auto i = mp.begin(); i != mp.end(); i++) {
            int temp = i->second;
            if (i->second > 0) {
                for (int j = i->first+k-1; j >= i->first; j--) {
                    if (mp[j] < i->second) return false;
                    mp[j] -= i->second;
                }
            }
        }
        return true;
    }
};