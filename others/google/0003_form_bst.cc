#include "../../common/Includes.h"

class Helper {
private:
    TreeNode *root;
    unordered_map<int,int> parentMap;

    void populate_map(TreeNode *curr, TreeNode *parent) {
        if (curr == NULL) return;
        if (parent != NULL) parentMap[curr->val] = parent->val;
        else parentMap[curr->val] = -1;
        populate_map(curr->left, curr);
        populate_map(curr->right, curr);
    }

public:
    Helper(TreeNode *root) {
        this->root = root;
        populate_map(root, NULL);
    }

    bool isParent(int x, int y) {
        return parentMap.find(x) != parentMap.end() ? parentMap[x] == y : false;
    }
};

class Solution {
private:
    Helper *helper;

    TreeNode *formBst(vector<int>& elements, int left, int right, int root) {
        int parentIndex = -1;
        for (int i = left; i <= right; i++) {
            if (helper->isParent(elements[i], root)) {
                parentIndex = i;
                break;
            }
        }
        if (parentIndex == -1) return NULL;

        TreeNode *parent = new TreeNode(elements[parentIndex]);
        parent->left = formBst(elements, left, parentIndex-1, elements[parentIndex]);
        parent->right = formBst(elements, parentIndex+1, right, elements[parentIndex]);
        return parent;
    }

public:
    TreeNode *formBst(vector<int> elements, Helper *helper) {
        sort(elements.begin(), elements.end());
        this->helper = helper;
        return formBst(elements, 0, elements.size()-1, -1);
    }
};

int main(void) {
    /**
     *              4
     *          2       6
     *      1      3  5    7
    */
    TreeNode *root = new TreeNode(
        4,
        new TreeNode(
            2,
            new TreeNode(1),
            new TreeNode(3)
        ),
        new TreeNode(
            6,
            new TreeNode(5),
            new TreeNode(7)
        )
    );
    vector<int> elements {1,2,3,4,5,6,7};
    Helper *helper = new Helper(root);
    Solution *solution = new Solution();
    TreeNode *answer = solution->formBst(elements, helper);
}