#include "../../../../common/Includes.h"

class Solution {
private:
    ListNode *_reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        /* Preconditions */
        if (head == NULL) return true;
        
        ListNode *fast = head, *slow = head;
                
        /* Find the middle */
        while (fast != NULL && fast->next != NULL) 
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        /* Odd nodes: let right half smaller */
        if (fast != NULL) 
        { 
            slow = slow->next;
        }
        
        /* Reverse the second half, and reset fast to the first half */
        slow = _reverse(slow);
        fast = head;

        /* Compare the two halves now */
        while (slow != NULL) 
        {
            if (fast->val != slow->val) 
            {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};