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
    unordered_map<string,TreeNode*> mem;
    set<TreeNode*> result;
    string fillMem(TreeNode* root) {
        if (root == NULL) return "";
        stringstream ss;
        ss << root->val;
        string code = fillMem(root->left) + "l" + ss.str() + "m" + fillMem(root->right) + "r";
        if (mem.count(code))
            result.insert(mem[code]);
        else
            mem[code] = root;
        return code;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        fillMem(root);
        vector<TreeNode*> answer(result.begin(), result.end());
        return answer;
    }
};