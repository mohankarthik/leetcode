#include "../../../../common/Includes.h"

class Solution {
private:
    void _update(int &pValue, int &pCarry)
    {
        if (pValue >= 10) 
        {
            pCarry = 1;
            pValue -= 10;
        }
        else
        {
            pCarry = 0;
        } 
    }
    
    int _findLength(ListNode *list) {
        int count = 0;
        ListNode *curr = list;
        while(curr != NULL) {
            curr = curr->next;
            count++;
        }
        return count;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1Ptr = l1, *l2Ptr = l2;
        uint32_t nL1Size = _findLength(l1);
        uint32_t nL2Size = _findLength(l2);
        ListNode *answer = NULL, *prevAnswer = NULL, *answerHead = NULL;
        
        /* Set the initial answer */
        if (nL1Size > nL2Size) answer = l1Ptr;
        else answer = l2Ptr;
        int carry = 0;
        answerHead = answer;
        
        /* Loop through the common portion of both lists */
        while((l1Ptr != NULL) && (l2Ptr != NULL)) 
        {
            int value = l1Ptr->val + l2Ptr->val + carry;
            _update(value, carry);
            
            prevAnswer = answer;
            answer->val = value;
            answer = answer->next;
            l1Ptr = l1Ptr->next;
            l2Ptr = l2Ptr->next;
        }
        
        /* Loop through the left over portion */
        while(l1Ptr != NULL)
        {
            int value = l1Ptr->val + carry;
            _update(value, carry);
            
            prevAnswer = answer;
            answer->val = value;
            answer = answer->next;
            l1Ptr = l1Ptr->next;
        }
        while(l2Ptr != NULL)
        {
            int value = l2Ptr->val + carry;
            _update(value, carry);
            
            prevAnswer = answer;
            answer->val = value;
            answer = answer->next;
            l2Ptr = l2Ptr->next;
        }
        
        /* Handle the last digit carry */
        if (carry > 0) {
            ListNode *newNode = new ListNode(carry);
            prevAnswer->next = newNode;
        }
        
        /* Return the head */
        return answerHead;
    }
};