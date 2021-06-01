// https://leetcode.com/problems/seat-reservation-manager/

class SeatManager {
public:
    set<int> st;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }
    }
    
    int reserve() {
        auto it = st.upper_bound(0);
        if (it != st.end()) {
            int rev = *it;
            st.erase(it);
            return rev;
        }
        return -1;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */