#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.length();
        char in[n + 1];
        (void)memset(in, 0, sizeof(char) * (n + 1));
        strncpy(in, s.c_str(), s.length());
        char *tok = strtok(in, " ");
        char *lastTok = NULL;
        while (tok)
        {
            lastTok = tok;
            tok = strtok(NULL, " ");
        }
        return lastTok ? strlen(lastTok) : 0;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    assert(sol->lengthOfLastWord("Hello World") == 5);
    assert(sol->lengthOfLastWord("") == 0);
}