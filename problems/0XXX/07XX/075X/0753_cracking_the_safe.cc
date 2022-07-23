#include "../../../../common/Includes.h"

class Solution {
private:
    unordered_set<string> visited;
    string answer;
    int n, k;
    int total;
    
    bool dfs(string curr) {
        if (visited.size() == total) {
            answer = curr;
            return true;
        }
        
        const string comb = curr.substr(curr.size()-(n-1));
        for (char ch = '0'; ch < '0' + k; ch++) {
            const string next = comb + ch;
            if (visited.count(next) > 0)
                continue;
            
            visited.insert(next);
            if (dfs(curr+ch))
                return true;
            visited.erase(next);
        }
        
        return false;
    }
public:
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        this->total = pow(k, n);
        answer = "";
        
        string curr = "";
        for (int i = 0; i < n; i++) {
            curr += "0";
        }
        visited.insert(curr);
        assert(dfs(curr) == true);
        return answer;
    }
};

int main(void) {
    Solution *sol = new Solution();
    sol->crackSafe(2, 2);
}