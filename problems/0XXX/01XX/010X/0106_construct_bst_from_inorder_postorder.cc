#include "../../../../common/Includes.h"

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
private:
    unordered_map<int,int> _idx_map;
    int n;
    int root_idx;
    vector<int> inorder;
    vector<int> postorder;
    
    TreeNode* _helper(int left, int right) {
        if (left > right or root_idx >= n) return NULL;
        
        int root_val = postorder[root_idx];
        TreeNode *root = new TreeNode(root_val);
        
        int index = _idx_map[root_val];
        root_idx--;
        
        root->right = _helper(index + 1, right);
        root->left = _helper(left, index - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        n = inorder.size();
        for(int i = 0; i < n; i++) _idx_map[inorder[i]] = i;
        root_idx = postorder.size() - 1;
        return _helper(0, n-1);
    }
};