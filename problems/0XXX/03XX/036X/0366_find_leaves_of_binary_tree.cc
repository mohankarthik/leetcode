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
    vector<vector<int>> result;
    
    int getMaxDepth(TreeNode* node) {
        if (node == NULL)
            return 0;
        
        return max(getMaxDepth(node->left), getMaxDepth(node->right)) + 1;
    }
    
    int collectAndRemoveLeaves(TreeNode* node) {
        // Collect & return true if this is a leaf,
        if (node->left == NULL and node->right == NULL) {
            result[0].push_back(node->val);
            return 0;
        }
        
        int leftHeight = (node->left != NULL) ? collectAndRemoveLeaves(node->left) + 1 : 0;
        int rightHeight = (node->right != NULL) ? collectAndRemoveLeaves(node->right) + 1 : 0;
        int curHeight = max(leftHeight,rightHeight);
        
        result[curHeight].push_back(node->val);
        node->left = NULL;
        node->right = NULL;
        
        return curHeight;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        result.resize(getMaxDepth(root));
        collectAndRemoveLeaves(root);
        return result;
    }
};