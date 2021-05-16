// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> vis;
    
    void traverse(int i, vector<vector<int>> &arr, int k) {
        if (vis[i]) return;
        
        if (k == 0) {
            ans.push_back(i);
        }
        
        vis[i] = 1;
        
        for (int j = 0; j < arr[i].size(); j++) {
            traverse(arr[i][j], arr, k-1);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        if (K == 0) return {target->val};
        
        vector<vector<int>> arr(501);
         
        vis = vector<int> (501);
        queue<TreeNode*> qs;
        qs.push(root);
        
        while(!qs.empty()) {
            auto node = qs.front();
            
            if (node->left != NULL) {
                arr[node->val].push_back(node->left->val);
                arr[node->left->val].push_back(node->val);
                qs.push(node->left);
            }
            
            if (node->right != NULL) {
                arr[node->val].push_back(node->right->val);
                arr[node->right->val].push_back(node->val);
                qs.push(node->right);
            }
            qs.pop();
        }
        
        traverse(target->val, arr, K);
        
        return ans;
    }
};