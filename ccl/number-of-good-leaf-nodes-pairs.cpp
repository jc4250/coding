//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans, dis;
    
    vector<int> getLeafNode(TreeNode* root) {
        if (root == NULL) return vector<int> (11);
        
        if (root->left == NULL && root->right == NULL) {
            vector<int> arr(11);
            arr[1]++;
            return arr;
        }
        
        auto left = getLeafNode(root->left);
        auto right = getLeafNode(root->right);
        
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if (i + j <= dis) {
                    ans += left[i]*right[j];
                }
            }
        }

        
        vector<int> arr(11);
        
        for (int i = 1; i < 10; i++) {
            arr[i+1] = left[i] + right[i]; 
        }
        return arr;
    }
    
    
    int countPairs(TreeNode* root, int distance) {
        dis = distance;
        getLeafNode(root);
        return ans;    
    }
};