#include <string>
#include <iostream>
#include <queue>
#include <assert.h>

class Solution {
public:
    std::string longestDiverseString(const int a, const int b, const int c) {
        std::string answer = "";
        char prev_char = 'z', prev_prev_char = 'z';
        
        // Form a PQ of char frequencies.
        std::priority_queue<std::pair<int, char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        while(!pq.empty()) {
            // Get the most frequent character
            auto [count1, char1] = pq.top();
            pq.pop();

            if (prev_char != char1 || prev_prev_char != char1) {
                answer += char1;
                
                // Add the char back into the PQ.
                --count1;
                if (count1) pq.push({count1, char1});

                // Update the prev characters
                prev_prev_char = prev_char;
                prev_char = char1;
            } else {
                // If no valid characters left, then exit
                if (pq.empty()) break;

                // Get the 2nd mopst frequent char to avoid repetitions
                auto [count2, char2] = pq.top();
                pq.pop();

                answer += char2;

                // Add the char back into the PQ.
                --count2;
                if (count2) pq.push({count2, char2});
                if (count1) pq.push({count1, char1});

                // Update the prev characters
                prev_prev_char = prev_char;
                prev_char = char2;
            }
        }
        return answer;
    }
};

int main(void) {
    Solution sol;
    assert(sol.longestDiverseString(7, 1, 0) == "aabaa");
    assert(sol.longestDiverseString(1, 1, 7) == "ccbccacc");
}