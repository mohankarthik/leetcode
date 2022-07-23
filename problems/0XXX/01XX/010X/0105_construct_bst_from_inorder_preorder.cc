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
    vector<int> preorder;
    vector<int> inorder;
    int n;
    int root_idx;
    
    /*
    (0,0,4) -> index=1
        (1,0,0) -> index=0
            (2,0,-1) X
            (3,1,0) X
        (2,2,4) -> index=3
            (3,2,2) -> index=2
                (4,2,-1) X
                (5,3,2) X
            (4,4,4) -> index=4
    */
    /*
    [1,2] [1,2]
    (0,0,1) -> index = 0
        (1,0,-1) X
        (1,1,1) -> index = 1
            (1,1,0) X
            (1,2,1) X
            
    */
    TreeNode* helper(int left, int right) {
        // Preconditions
        if (left > right or root_idx >= n) return NULL;
        
        int index = _idx_map[preorder[root_idx]];
        
        // Create the new node
        TreeNode* node = new TreeNode(preorder[root_idx]);
        root_idx++;
        
        node->left = helper(left, index-1);
        node->right = helper(index+1, right);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->inorder = inorder;
        this->preorder = preorder;
        n = preorder.size();
        
        for (int i = 0; i < n; i++) _idx_map[inorder[i]] = i;
        root_idx = 0;
        return helper(0, n-1);
    }
};