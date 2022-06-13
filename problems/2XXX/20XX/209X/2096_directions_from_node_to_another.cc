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
    bool find(TreeNode* cur, int target, string& path) {
        if (cur->val == target) return true;
        
        if (cur->left and find(cur->left, target, path)) path += "L";
        else if (cur->right and find(cur->right, target, path)) path += "R";
        
        return !path.empty();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        find(root, startValue, startPath);
        find(root, destValue, destPath);
        
        // Remove common prefix (currently at the back)
        while (!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()) {
            startPath.pop_back();
            destPath.pop_back();
        }
        
        return string(startPath.size(), 'U') + string(rbegin(destPath), rend(destPath));
    }
};