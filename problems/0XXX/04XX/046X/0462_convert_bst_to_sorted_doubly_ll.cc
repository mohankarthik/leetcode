#include "../../../../common/Includes.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
private:
    Node* head = NULL;
    Node* tail = NULL;
    
    void _dfs(Node* node) {
        if (node) {
            // Search left
            _dfs(node->left);
            
            // If left has set a tail, then attach node to the end of the tail,
            // else assume node to be the head (because left was null)
            if (tail) {
                tail->right = node;
                node->left = tail;
            } else {
                head = node;
            }
            
            // Set node as the tail because we've basically done left, and hence node is in all
            // scenarios basically the tail node
            tail = node;
            
            // Now do right, and since node is tail, this call will basically attach whatever forms
            // later to the right of this
            _dfs(node->right);
        }
    }
    
    
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        
        _dfs(root);
        
        tail->right = head;
        head->left = tail;
        
        return head;
        
    }
};