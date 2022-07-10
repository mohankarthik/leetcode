#include "../../../../common/Includes.h"

class Solution {
private:
    vector<string> genStrobogrammatic(int n, int length) {
        if (n == 0) return {};
        if (n == 1) return {"0", "1", "8"};
        
        vector<string> middles = genStrobogrammatic(n-2, length);
        vector<string> result = middles;
        for (const string& middle: middles) {
            if (n != length) {
                result.push_back("0" + middle + "0");
            }
            result.push_back("1" + middle + "1");
            result.push_back("6" + middle + "9");
            result.push_back("8" + middle + "8");
            result.push_back("9" + middle + "6");
        }
        return result;
    }
    
    int filter(const string& lowStr, const string& highStr, const vector<string>& values) {
        int low = stoi(lowStr);
        int high = stoi(highStr);
        
        int result = 0;
        for (const string& valStr: values) {
            const int val = stoi(valStr);
            if (low <= val and val <= high)
                result++;
        }
        
        return result;
    }
public:
    int strobogrammaticInRange(const string& low, const string& high) {
        return filter(low, high, genStrobogrammatic(high.length(), high.length()));
    }
};

int main(void){
    Solution *sol = new Solution();
    sol->strobogrammaticInRange("50", "100");
}