#include "../../../../common/Includes.h"

class Solution {
private:
    ListNode *_reverseListRec(ListNode *head, ListNode *newHead) {
        /* End condition */
        if (head == NULL) return newHead;
        
        ListNode *next = head->next;
        head->next = newHead;
        return _reverseListRec(next, head);
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        return _reverseListRec(head, NULL);
    }
};