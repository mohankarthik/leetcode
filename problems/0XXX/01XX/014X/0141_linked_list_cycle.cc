#include "../common/Includes.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr1 = head, *ptr2 = head;
        
        /* Preconditions */
        if(head == NULL) return false;
        
        while(ptr2->next != NULL && ptr2->next->next != NULL) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if (ptr1 == ptr2) return true;
        }
        return false;
    }
};