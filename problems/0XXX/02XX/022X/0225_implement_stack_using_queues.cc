#include "../../../../common/Includes.h"

class MyStack {
private:
    queue<int>* q;
public:
    MyStack() {
        q = new queue<int>;
    }
    
    void push(int x) {
        q->push(x);
    }
    
    int pop() {
        int res = q->back();
        
        // remove only required value by address, not by int
        int* address = (int*)q->back();
        
        while(true)
        {
            // remove element
            if((int*)q->front() == address)
            {
                q->pop();
                break;
            }
            // circle - add to begin and remove current
            q->push(q->front());
            q->pop();
        }
        
        return res;
    }
    
    int top() {
        return q->back();
    }
    
    bool empty() {
        return q->empty();
    }
};