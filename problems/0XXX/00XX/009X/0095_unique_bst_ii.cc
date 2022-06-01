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
    vector<TreeNode*> _generateTrees(int min, int max) {
        vector<TreeNode*> ans;
        if (min > max) {
            ans.push_back(NULL);
            return ans;
        }
        
        for (int i = min; i <= max; i++) {
            auto leftTrees = _generateTrees(min, i-1);
            auto rightTrees = _generateTrees(i+1, max);
            
            for(auto leftTree: leftTrees) {
                for (auto rightTree: rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
        
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return _generateTrees(1,n);
    }
};