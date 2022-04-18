#include "../common/Includes.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /* Preconditions */
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* firstp = head;
        ListNode* secondp = head;
        bool isCycle = false;

        /* Do the 2 pointers to find if there is a cycle or not */
        while(firstp != NULL && secondp != NULL) {
            firstp = firstp->next;
            if (secondp->next == NULL) return NULL;
            secondp = secondp->next->next;
            if (firstp == secondp) { isCycle = true; break; }
        }

        /* If there is no cycle, return */
        if(!isCycle) return NULL;
        
        /**
        Assume the distance from head to the start of the loop is x1
        the distance from the start of the loop to the point fast and slow meet is x2
        the distance from the point fast and slow meet to the start of the loop is x3
        
        What is the distance fast moved?
        x1 + x2 + x3 + x2
        
        What is the distance slow moved?
        x1 + x2
        
        And their relationship?
        x1 + x2 + x3 + x2 = 2 (x1 + x2)
        
        Thus x1 = x3
        
        So, to find x1, set firstp back to head. secondp is now at x1+x2. 
        Making secondp move x3 = x1 will also make it loop around and reach the 
        meeting point in the same set of steps.
        */
        firstp = head;
        while( firstp != secondp) {
            firstp = firstp->next;
            secondp = secondp->next;
        }

        return firstp;
    }
};