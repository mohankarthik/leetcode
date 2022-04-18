#include "../../../../common/Includes.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* A start node is needed to ensure that we can remove head also in a uniform manner
        Since it's n nodes from end, and if n = list.size(), we would be removing head, but won't
        know about it
        */
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *slow = start, *fast = start;
        
        /* Move the fast to n steps ahead */
        for (int i = 0; i < n+1; i++) fast = fast->next;
        
        /* Move both until fast hits NULL. So now slow is at the position we need */
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        /* Remove the node */
        slow->next = slow->next->next;
        
        /* Return */
        return start->next;
    }
};