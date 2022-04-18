#include "../../../../common/Includes.h"

class Solution {
private:
    // Function for unique checker
    static inline bool _bothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }
    
    // trim from start (in place)
    static inline void _ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void _rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    // trim from both ends (in place)
    static inline void _trim(std::string &s) {
        _ltrim(s);
        _rtrim(s);
        std::string::iterator new_end = std::unique(s.begin(), s.end(), _bothAreSpaces);
        s.erase(new_end, s.end());
    }
    
public:
    string reverseWords(string s) {
        /* Preconditions */
        if(s.size() == 0) return s;
        
        /* Trim the string */
        _trim(s);
        
        /* Reverse each word */
        int l = 0;
        int r = 1;
        for (; r < s.size(); r++) {
            if (s[r] == ' ') {
                reverse(s.begin()+l, s.begin()+r);
                l = r+1;
            }
        }
        reverse(s.begin()+l, s.end());
        
        /* Reverse the whole string */
        reverse(s.begin(), s.end());
        _trim(s);
        
        return s;
    }
};