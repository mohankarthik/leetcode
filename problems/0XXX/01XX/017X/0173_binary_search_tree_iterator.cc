#include "../common/Includes.h"

class BSTIterator {
private:
    vector<int> _array;
    int _pos;
    
    void _inOrderTraverse(TreeNode *root) {
        if (root->left != NULL) _inOrderTraverse(root->left);
        _array.push_back(root->val);
        if (root->right != NULL) _inOrderTraverse(root->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        _inOrderTraverse(root);
        _pos = 0;
    }
    
    int next() {
        return _array[_pos++];
    }
    
    bool hasNext() {
        return _pos < _array.size();
    }
};