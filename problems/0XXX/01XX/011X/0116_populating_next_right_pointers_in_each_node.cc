#include "../../../../common/Includes.h"

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

		Node* ptr = root;
		Node* startPtr = ptr->left;

		while (startPtr) {
			while (ptr) {
				ptr->left->next = ptr->right;
				ptr->right->next = ptr->next != NULL ? ptr->next->left : NULL;
				ptr = ptr->next;
			}

			ptr = startPtr;
			startPtr = startPtr->left;
		}

		return root;
    }
};