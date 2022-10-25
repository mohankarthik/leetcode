#include "../../../../common/Includes.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string left, right;
        for (const string& word: word1) left += word;
        for (const string& word: word2) right += word;
        return (left == right);
    }
};