#include "../../../../common/Includes.h"

class Solution
{
private:
    stack<int> _stack;

    void _getArgs(int &arg1, int &arg2)
    {
        arg2 = _stack.top();
        _stack.pop();
        arg1 = _stack.top();
        _stack.pop();
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        for (int i = 0; i < tokens.size(); i++)
        {
            int val1, val2;
            if (tokens[i] == "+")
            {
                _getArgs(val1, val2);
                _stack.push(val1 + val2);
            }
            else if (tokens[i] == "-")
            {
                _getArgs(val1, val2);
                _stack.push(val1 - val2);
            }
            else if (tokens[i] == "*")
            {
                _getArgs(val1, val2);
                _stack.push(val1 * val2);
            }
            else if (tokens[i] == "/")
            {
                _getArgs(val1, val2);
                _stack.push(val1 / val2);
            }
            else
                _stack.push(stoi(tokens[i]));
        }

        return _stack.top();
    }

    void clear()
    {
        while (!_stack.empty())
            _stack.pop();
    }
};