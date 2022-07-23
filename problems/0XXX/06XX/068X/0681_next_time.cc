#include "../../../../common/Includes.h"

class Solution {
private:
    bool IsValid(const string& time)
    {
        return 
            (time.substr(0, 2) < string("24")) && 
            (time.substr(2, 2) < string("60"));
    }

    bool IsAfter(const string& one, const string& two)
    {
        return one > two;
    }
public:
    string nextClosestTime(string time) {
        string t = time.substr(0, 2) + time.substr(3, 2);
        set<char> digits;
        for (int i = 0; i < t.size(); i++) digits.insert(t[i]);

        string answer = t;
        int index = 3;
        while (index >= 0)
        {
            for (auto iter = digits.begin(); iter != digits.end(); ++iter)
            {
                answer[index] = *iter;
                if (IsValid(answer) && IsAfter(answer, t))
                {
                    return answer.substr(0, 2) + ":" + answer.substr(2, 2);
                }
            }
            answer[index] = *digits.begin();
            index--;
        }
        return answer.substr(0, 2) + ":" + answer.substr(2, 2);;
    }
};