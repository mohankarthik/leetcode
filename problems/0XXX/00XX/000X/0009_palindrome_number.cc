#include "../../../../common/Includes.h"

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string s = to_string(x);
        int n = s.length();
        for (int i = 0; i <= (n / 2); i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->isPalindrome(121) == true);
    assert(sol->isPalindrome(-121) == false);
    assert(sol->isPalindrome(10) == false);
    assert(sol->isPalindrome(-101) == false);
}