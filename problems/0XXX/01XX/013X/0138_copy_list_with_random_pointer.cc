#include "../common/Includes.h"

class Solution {
private:
    void _print(Node *head)
    {
        Node *curr = head;
        while(curr != NULL) {
            cout << curr->val << "-->";
            curr = curr->next;
        }
        cout << endl;
    }
    
public:
    Node* copyRandomList(Node* head) {
        /* Preconditions */
        if (head == NULL) return NULL;
        
        Node *newHead, *l1, *l2;
        
        /* Do a first pass and make copies of all nodes */
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
        }
        
        /* Do a second pass, fix all the random connections */
        newHead = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random != NULL) l1->next->random = l1->random->next;
        }
        
        /* Do a 3rd pass and fix all the connections */
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL) l2->next = l2->next->next;
        }
        
        return newHead;
    }
};