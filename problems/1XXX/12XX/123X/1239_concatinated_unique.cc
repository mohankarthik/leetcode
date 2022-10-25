#include "../../../../common/Includes.h"

class Solution {
private:
    int n;
    vector<string> orig;
    unordered_map<string,int> seen;
    
    bool is_unique(const string& str) {
        const unordered_set<char> unique(str.begin(), str.end());
        return unique.size() == str.length();
    }
    
    int helper(int i, string curr) {
        if(!is_unique(curr)) 
            return 0;
        
        if (seen.count(curr) > 0)
            return seen[curr];
        
        if(i == n) {
            seen[curr] = curr.size();
            return seen[curr];
        }
        
        int temp = 0;
        temp = helper(i + 1, curr + orig[i]);
        temp = max(temp, helper(i + 1, curr));

        seen[curr] = temp;
        return temp;
    }
    
public:
int maxLength(const vector<string>& arr) {
    this->n = arr.size();
    this->orig = arr;
    // call helper function
    return helper(0, "");
}};