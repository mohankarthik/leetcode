#include "../../../../common/Includes.h"

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Master {
public:
    int guess(string word);
};

class Solution {
private:
    int getMatches(string str1, string str2) {
        int matches = 0;
        for (int i = 0; i < 6; i++) 
            if (str1[i] == str2[i])
                matches++;
        return matches;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(0));
        int matches = 0;
        for (int step = 0; step < 10; step++) {
            
            string currWord = wordlist[rand() % wordlist.size()];
            matches = master.guess(currWord);
            cout << currWord << " " << matches << " " << wordlist.size() << endl;
            if (matches == 6)
                return;
            
            vector<string> candidates;
            for (string word: wordlist) {
                if (matches == getMatches(word, currWord))
                    candidates.push_back(word);
            }
            swap(candidates, wordlist);
        }
    }
};