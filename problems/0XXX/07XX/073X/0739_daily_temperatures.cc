#include "../../../../common/Includes.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        /* Initialize the results */
        vector<int> results(T.size(), 0);
        
        /* Create a stack */
        stack<int> _stack;
        
        /* Loop through each element */
        for (int i = 0; i < T.size(); i++) 
        {
            /* Check if the current value is > the top value in the stack */
            while (!_stack.empty() && (T[i] > T[_stack.top()]))
            {
                int idx = _stack.top();
                _stack.pop();
                results[idx] = i-idx;
            }
            _stack.push(i);
        }
        
        return results;
    }
};