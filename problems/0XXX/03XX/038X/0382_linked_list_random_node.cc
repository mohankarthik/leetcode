#include "../../../../common/Includes.h"

class Solution {
private:
    ListNode *_head;
    int _size = 0;
    
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode *curr = head;
        this->_head = head;
        
        while(curr != NULL) 
        {
            this->_size++;
            curr = curr->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int rnd = rand() % this->_size;
        ListNode *curr = this->_head;
        
        while(rnd--)
        {
            curr = curr->next;
        }
        return curr->val;
    }
};