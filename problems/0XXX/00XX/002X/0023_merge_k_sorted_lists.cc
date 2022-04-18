#include "../../../../common/Includes.h"

class Solution {
private:
    /** Private function that takes 2 sorted lists and merges them
     * retaining the attribute of it being sorted */
    ListNode* _mergeLists(ListNode* l1, ListNode* l2) {
        /* Handle corner cases */
        if (!l1) return l2;
        if (!l2) return l1;
        
        /* Set the head to the least start */
        ListNode* head = (l1->val <= l2->val) ? l1 : l2;
        
        /* Recursively merge the lists */
        head->next = (l1->val <= l2->val) ? _mergeLists(l1->next, l2) : _mergeLists(l1, l2->next);
        
        /* Return */
        return head;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        /* Handle corner case */
        if (k == 0) return NULL;
        
        /* Set the head arbitrarily */
        ListNode* head = lists[0];
        
        /* Loop and merge each to head */
        for (int i = 1; i < k; i++)
            head = _mergeLists(head, lists[i]);
        
        /* Return */
        return head;
    }
};