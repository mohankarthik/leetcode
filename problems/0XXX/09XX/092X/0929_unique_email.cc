#include "../../../../common/Includes.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> answer;
        for (auto const &email: emails) {
            string parsedEmail = "";
            int curPart = 0;
            for (int i = 0; i < email.length(); i++) {
                if (curPart == 0) {
                    if (email[i] >= 'a' and email[i] <= 'z') {
                        parsedEmail += email[i];
                    } else if (email[i] == '+') {
                        curPart = 1;
                    } else if (email[i] == '@') {
                        parsedEmail += email[i];
                        curPart = 2;
                    }
                } else if (curPart == 1) {
                    if (email[i] == '@') {
                        parsedEmail += email[i];
                        curPart = 2;
                    }
                } else {
                    parsedEmail += email[i];
                }
            }
            cout << parsedEmail << endl;
            answer.insert(parsedEmail);
        }
        return answer.size();
    }
};