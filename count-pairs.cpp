//https://leetcode.com/problems/count-pairs-with-xor-in-a-range/

class Solution {
public:
    const int LVL = 16;
    
    struct TrieNode {
        TrieNode* child[2];
        int cnt;
        TrieNode() {
            cnt = 0;
            child[0]=NULL;
            child[1]=NULL;
        }
    };
    
    void insertTrieNode(int n, TrieNode* root) {
        for (int i = LVL; i >= 0; i--) {
            bool bit = (1<<i) & n;
            
            if (root->child[bit] == NULL) {
                root->child[bit] = new TrieNode();
            }
            root->child[bit]->cnt += 1;
            root = root->child[bit];
        }    
    }
    
    int getNicePair(int num, TrieNode* root, int high) {
        
        int temp = 0;
        TrieNode* rootnode = root;
        for (int i = LVL; i >= 0 && root != NULL; i--) {
            bool n = num & (1<<i);
            bool k = high & (1<<i);
            
            if (k == 0) {
                root = root->child[n];
                continue;
            } 
            
            if (root->child[n]) {
                temp += root->child[n]->cnt;
            }
            
            root = root->child[n ^ 1];
        }
        return temp;
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        struct TrieNode* root = new TrieNode();
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += getNicePair(nums[i], root, high+1);
            ans -= getNicePair(nums[i], root, low);
            insertTrieNode(nums[i], root);
        }
        
        return ans;
    }
};