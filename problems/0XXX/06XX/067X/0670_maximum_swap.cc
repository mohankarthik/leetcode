#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class Solution {
public:
    int maximumSwap(const int num) {
        // Convert the number to a string for easier digit manipulation
        std::string numStr = std::to_string(num);
        const int n = numStr.size();
        
        // Store the last occurrence of each digit (0-9)
        std::vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse each digit from left to right
        for (int i = 0; i < n; ++i) {
            // Check if there's a larger digit appearing later
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap the current digit with the larger one
                    std::swap(numStr[i], numStr[last[d]]);
                    return std::stoi(numStr); // Convert back to integer and return
                }
            }
        }
        
        // If no swap was made, return the original number
        return num;

    }
};

int main(void) {
    Solution sol;
    assert(sol.maximumSwap(2736) == 7236);
    assert(sol.maximumSwap(9943) == 9943);
}