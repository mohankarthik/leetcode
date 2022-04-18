#include "../../../../common/Includes.h"

class Solution {
private:
    int sz = 0;
    string _decode(string &s, int &i)
    {
        string result = "";
        while(i < sz && s[i] != ']')
        {
            if (!isdigit(s[i]))
            {
                result += s[i];
                i++;
            }
            else
            {
                /* Get the number */
                int n = 0;
                while(isdigit(s[i]))
                {
                    n = (n * 10) + s[i] - '0';
                    i++;
                }
                
                /* Pass the [ */
                i++;
                
                /* Decode the substring */
                string sub = _decode(s, i);
                
                /* Pass the ] */
                i++;
                    
                /* Add the string */
                while(n-- > 0)
                    result += sub;
            }
        }
        return result;
    }
public:
    string decodeString(string s) {
        int i = 0;
        sz = s.size();
        return _decode(s, i);
    }
};