#include "../common/Includes.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        /* Preconditions */
        if (root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); /* Use NULL as a marker to say end of level */
        
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            
            /* If marker */
            if (t==NULL) {
                ans.push_back(curr);
                curr.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                curr.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        
        return ans;
    }
};