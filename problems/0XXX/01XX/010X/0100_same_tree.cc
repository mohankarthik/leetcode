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
    bool _isSameNode(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL) return true;
        if (p == NULL or q == NULL) return false;
        return p->val == q->val;
    }
    
    bool _recurse(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL) return true;
        if (p == NULL or q == NULL) return false;
        if (p->val != q->val) return false;
        
        return 
            (_recurse(p->left, q->left)
            and _recurse(p->right, q->right));
    }
    
    bool _iterate(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pStack;
        stack<TreeNode*> qStack;
        
        if (!_isSameNode(p, q)) return false;
        if (p == NULL) return true;
        
        pStack.push(p);
        qStack.push(q);
        
        while(!pStack.empty() and !qStack.empty()) {
            TreeNode* currP = pStack.top(); pStack.pop();
            TreeNode* currQ = qStack.top(); qStack.pop();
            
            if (!_isSameNode(currP->left, currQ->left)) return false;
            if (!_isSameNode(currP->right, currQ->right)) return false;
            
            if (currP->left != NULL) {
                pStack.push(currP->left);
                qStack.push(currQ->left);
            }
            if (currP->right != NULL) {
                pStack.push(currP->right);
                qStack.push(currQ->right);
            }
        }
        
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return _iterate(p, q);
    }
};