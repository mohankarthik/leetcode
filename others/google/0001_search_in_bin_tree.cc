#include "../../common/Includes.h"

/* https://leetcode.com/discuss/interview-question/2180421/Google-or-Virtual-Onsite-L3-SWE-or-Question */

class Solution {
private:
    int findLevel(TreeNode *left, TreeNode *right, int target) {
        if (left->val <= target and target <= right->val)
            return 0;
        
        if (left == NULL or right == NULL)
            return -1;
        
        return findLevel(left->left, right->right, target) + 1;
    }

    int getNode(TreeNode *root, int level, int idx) {
        int left = 0, right = ((1 << level) - 1);
        int pivot;
        TreeNode *curr = root;
        for(int i = 0; i < level; ++i) {
            pivot = left + (right - left) / 2;
            if (idx <= pivot) {
                curr = curr->left;
                right = pivot;
            }
            else {
                curr = curr->right;
                left = pivot + 1;
            }
        }
        return curr->val;
    }

public:
    bool searchNumber(TreeNode *root, int target) {
        const int level = findLevel(root, root, target);
        if (level == 0)
            return target == root->val;
        
        int left = 0;
        int right = ((1 << level) - 1);
        
        while(left <= right) {
            const int mid = left + ((right - left) / 2);
            const int midVal = getNode(root, level, mid);
            if (target == midVal) return true;
            else if (target >= midVal) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

int main(void) {
    TreeNode *root = new TreeNode(
        1,
        new TreeNode(
            2,
            new TreeNode(4),
            new TreeNode(10)
        ),
        new TreeNode(
            3,
            new TreeNode(20),
            new TreeNode(30)
        )
    );
    Solution *sol = new Solution();
    assert(sol->searchNumber(root, 5) == false);
    assert(sol->searchNumber(root, 20) == true);
    assert(sol->searchNumber(root, 3) == true);
}