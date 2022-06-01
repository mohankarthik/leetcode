#include "../../../../common/Includes.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* _iterate(ListNode* l1, ListNode* l2) {
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

    ListNode* _recurse(ListNode *l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val) {
            l1->next = _recurse(l1->next, l2);
            return l1;
        }
        l2->next = _recurse(l1, l2->next);
        return l2;
    }    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return _recurse(l1, l2);
    }
};