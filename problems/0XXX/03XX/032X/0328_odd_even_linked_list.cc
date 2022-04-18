#include "../../../../common/Includes.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        /* Preconditions */
        if (head == NULL) return NULL;
        
        ListNode *odd = head, *even = head->next, *evenHead = even;
    
        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next; 
            even->next = even->next->next; 
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
    }
};