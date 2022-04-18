#include "../../../../common/Includes.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *phantom = new ListNode(0);
        phantom->next = NULL;
        
        ListNode *l1Ptr = l1, *l2Ptr = l2;
        ListNode *curr = phantom;
        while((l1Ptr != NULL) && (l2Ptr != NULL)) 
        {
            if (l1Ptr->val < l2Ptr->val)
            {
                curr->next = l1Ptr;
                curr = curr->next;
                l1Ptr = l1Ptr->next;
            }
            else
            {
                curr->next = l2Ptr;
                curr = curr->next;
                l2Ptr = l2Ptr->next;
            }
        }
        while(l1Ptr != NULL) 
        {
            curr->next = l1Ptr;
            curr = curr->next;
            l1Ptr = l1Ptr->next;
        }
        while(l2Ptr != NULL)
        {
            curr->next = l2Ptr;
            curr = curr->next;
            l2Ptr = l2Ptr->next;
        }
        return phantom->next;
    }
};