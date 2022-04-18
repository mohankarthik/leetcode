#include "../../../../common/Includes.h"

class Solution {
private:
    /**
     * Flattens a sub segment of the list and returns the tail
     */
    Node* _flattenRec(Node* head) {
        /* Save the values */
        Node *next = head->next;
        Node *child = head->child;
        Node *childLast = NULL;
        Node *nextLast = NULL;
        Node *tail = head;
        
        /* Flatten the child segment */
        if (child != NULL) 
        {
            childLast = _flattenRec(child);
            childLast->next = NULL;
            
            head->next = child;
            child->prev = head;
            
            tail = childLast;
            
            head->child = NULL;
        }
        
        /* Flatten the next segment */
        if (next != NULL) 
        {
            nextLast = _flattenRec(next);
            nextLast->next = NULL;
            
            /* If child was there */
            if (child != NULL)
            {
                childLast->next = next; 
                next->prev = childLast;
            }
            
            tail = nextLast;
        }
        
        /* Return the tail */
        return tail;
    }
    
public:
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;
        Node * tail = _flattenRec(head);
        tail->next = NULL;
        return head;
    }
};