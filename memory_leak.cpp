//https://leetcode.com/problems/incremental-memory-leak/

class Solution {
public:
    vector<int> memLeak(int mem1, int mem2) {
        int time = 1;
        
        while (time <= mem1 || time <= mem2) {
            if (mem1 >= mem2) {
                mem1 -= time;
            } else {
                mem2 -= time;
            }
            time++;
        }
        
        return {time, mem1, mem2};
    }
};