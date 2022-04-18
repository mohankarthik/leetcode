#include "../../../../common/Includes.h"

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            Node *newHead = new Node(insertVal);
            newHead->next = newHead;
            return newHead;
        }
        
        Node *curr = head;
        Node *next = curr->next;
        bool inserted = false;
        while(true) {
            /* Insert in between, or at the end */
            if ((curr->val <= insertVal && insertVal <= next->val)
                || (curr->val > next->val && insertVal < next->val)
                || (curr->val > next->val && insertVal > curr->val)){
                curr->next = new Node(insertVal, next);
                inserted = true;
                break;
            }
            curr = next;
            next = curr->next;
            if (curr == head)
                break;
        }
        
        /* Only reason is all the values are the same, and not = insertValue.
        Just insert it anywhere */
        if (!inserted) {
            curr->next = new Node(insertVal, next);
        }
        
        return head;
    }
};