//https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sh = stoi(startTime.substr(0, 2));
        int sm = stoi(startTime.substr(3));
        
        int fh = stoi(finishTime.substr(0, 2));
        int fm = stoi(finishTime.substr(3));
        
        if (fh == sh && fm == sm) return 0;
        
        if (fh < sh ||(fh == sh && fm < sm)) {
            fh += 24;
        }
        
        int ans = 0;
        if ((sm == 0 && fm == 0) || (sm == 15 && fm == 15) || (sm == 30 && fm == 30) || (sm == 45 && fm == 45)) {
            ans = (fh - sh) * 4;
            return ans;
        }
        
        
        fm = floor((fm * 1.0)/15);
        sm = ceil((sm * 1.0)/15);
        
        if (fm < sm && fh > sh) {
            fm += 4;
            fh -= 1;
        }
        
        // cout<<sh<<" "<<sm<<" "<<fh<<" "<<fm<<endl;
        ans = (fh - sh) * 4 + fm - sm;
        
        return ans;
    }
};