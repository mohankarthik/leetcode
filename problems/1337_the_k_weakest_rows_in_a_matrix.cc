#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct PriorityQueueComparator {
    bool operator()(pair<int,int> const &p1, pair<int,int> const &p2) {
        // Compare the number of soldiers
        if (p1.first < p2.first)
            return true;
        // Compare the indices
        else if (p1.first == p2.first && p1.second < p2.second)
            return true;
        return false;
    }
};

class Solution {
private:
    int n, m;
    
    // Finds the number of soldiers in a particular row using binary search
    int findNumSoldiers(vector<int>& row) {
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (row[mid] == 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    
    /* Find the answer by looping through each row, finding the number of soldiers,
    then, adding that to a priority queue and forming the answer */
    vector<int> usingMaxHeap(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, PriorityQueueComparator> queue;
        
        // Iterate, add new elements and keep the queue size to a maximum of k
        for (int i = 0; i < n; i++) {
            queue.push({findNumSoldiers(mat[i]), i});
            if (queue.size() > k)
                queue.pop();
        }
        
        // Pop out from the queue and make the answer
        vector<int> ans;
        while(!queue.empty()) {
            auto val = queue.top();
            ans.push_back(val.second);
            queue.pop();
        }
        
        // Reverse
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> usingSort(vector<vector<int>>& mat, int k) {
        // Add the index into each row, so that sort can automatically take care of both conditions
        for (int i = 0; i < n; i++) {
            mat[i].push_back(i);
        }
        
        // Sort
        sort(mat.begin(), mat.end());
        
        // Form the answer
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            // Add the index of the array into the answer
            ans.push_back(mat[i][m]);
        }
        return ans;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Preconditions
        if (mat.empty() || mat[0].empty())
            throw invalid_argument("mat is empty");
        
        // Store the sizes
        n = mat.size();
        m = mat[0].size();
        
        // return usingMaxHeap(mat, k);
        return usingSort(mat, k);
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<vector<int>> grid1 = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };
    vector<int> ans1 = {2,0,3};
    assert(sol->kWeakestRows(grid1, 3) == ans1);

    vector<vector<int>> grid2 = {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };
    vector<int> ans2 = {0,2};
    assert(sol->kWeakestRows(grid2, 2) == ans2);
    return 0;
}