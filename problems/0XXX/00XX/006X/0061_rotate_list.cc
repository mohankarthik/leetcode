#include "../common/Includes.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        /* Preconditions */
        if(!head) return NULL;
        
        ListNode *curr = head, *newHead = NULL;
        uint32_t nLen = 1;
        uint32_t i = 0;
        
        /* Find the length */
        for (curr = head; curr->next; curr = curr->next, nLen++) { }
        
        /* Sanitize the k */
        k = k % nLen;
        
        /* Make a loop */
        curr->next = head;
        
        /* Move to nLen - k and break the link and make a new head */
        for (i = 0, curr = head; i < (nLen - k - 1); i++, curr=curr->next) {}
        newHead = curr->next;
        curr->next = NULL;
        
        return newHead;
    }
};