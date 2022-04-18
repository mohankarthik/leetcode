#include "../common/Includes.h"

class Solution
{
private:
    int _findLevels(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = _findLevels(root->left);
        int right = _findLevels(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return _findLevels(root) != -1;
    }
};