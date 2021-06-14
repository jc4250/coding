//https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<string>> arr;
    unordered_map<string, vector<int>> time;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if (arr.count(key) == 0) {
            
            arr[key] = {value};
        } else {
            arr[key].push_back(value);
        }
        
        if (time.count(key) == 0) {
            
            time[key] = {timestamp};
        } else {
            time[key].push_back(timestamp);
        }
    }
    
    string get(string key, int timestamp) {
        int l = 0, h = time[key].size()-1;
        
        int ans = -1;
        while (l <= h) {
            
            int mid = l + (h - l)/2;
            
            if (time[key][mid] <= timestamp) {
                l = mid + 1;
                ans = mid;
            } else {
                h = mid - 1;
            }
        }
        
        if (ans == -1) return "";
        return arr[key][ans];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */