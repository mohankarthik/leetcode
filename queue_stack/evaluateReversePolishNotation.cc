#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

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

int main(void)
{
    Solution *sol = new Solution();
    vector<string> input{"2", "1", "+", "3", "*"};
    sol->clear();
    assert(sol->evalRPN(input) == 9);

    input = {"4", "13", "5", "/", "+"};
    sol->clear();
    assert(sol->evalRPN(input) == 6);

    input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    sol->clear();
    assert(sol->evalRPN(input) == 22);
}