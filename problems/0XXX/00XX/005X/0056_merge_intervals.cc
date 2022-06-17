/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
Intervals may not be sorted

*/

/*
Sol 1: Loop through the array, merge, and repeat until no more left to merge -> O(n^3)
Sol 2: 
1 - ST
3 - ST
3 - ST
3 - EN
4 - ST
6 - EN
6 - EN
10 - EN

Array size (10^8)
vector<pair<int,bool>> 

Sol3:

[[1,3],[3,6],[3,10],[4,6],[15,18]]
if (map contains(st)) {
  if (map[st] == en) erase the entry & not fill
  if (map[st] == st) 
}

https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/

https://www.tutorialspoint.com/Sorting-a-vector-of-custom-objects-using-Cplusplus-STL#:~:text=You%20can%20sort%20a%20vector%20of%20custom%20objects,used%20to%20tell%20how%20to%20sort%20the%20container.
//define the function:
bool comparator(const MyStruct& lhs, const MyStruct& rhs) {
   return lhs.key < rhs.key;
}
// pass it to sort:
sort(vec.begin(), vec.end(), &comparator);
*/
#include "../../../../common/Includes.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> answer;
        for (auto interval: intervals) {
            if (answer.empty() or answer.back()[1] < interval[0])
                answer.push_back(interval);
            else
                answer.back()[1] = max(answer.back()[1], interval[1]);
        }

        return answer;
    }
};

int main() {
    Solution *sol = new Solution();
  vector<vector<int>> input{
    {1,3},
    {3,6},
    {2,10},
    {3,10},
    {15,18}
  };
  auto output = sol->merge(input);
  for (auto row: output) {
    for (auto val: row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

//https://www.techiedelight.com/sort-vector-pairs-cpp/



