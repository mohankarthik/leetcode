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


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pair_sort {
  bool operator ()(const pair<int, bool> &x, const pair<int, bool> &y) const {
    if (x.first != y.first)
      return x.first < y.first;
    return x.second == true ? true : false;
  }
};

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
  vector<pair<int,bool>> nodes;
  
  // Fill the nodes
  for (auto interval: intervals) {
    nodes.push_back({interval[0],true});
    nodes.push_back({interval[1],false});
  }
  
  // Sort the array
  sort(nodes.begin(), nodes.end(), pair_sort());
  
  /**
  [[1,3],[3,6],[3,10],[15,18]]
  XXXX           -1
  1 - True - 1 - 1
  3 - True - 2 - 1
  3 - True - 3 - 1
  3 - False - 2 - 1
  6 - False - 1 - 1
  10 - False - 0 - -1 {{1,10}}
  15 - True - 1 - 15
  18 - False - 0 - -1 {{1,10},{15,18}}
  */
  vector<vector<int>> answer;
  int st = -1;
  int depth = 0;
  for (auto node: nodes) {
    if (node.second == true)
      depth++;
    else
      depth--;
    
    if (depth == 1 and st == -1)
      st = node.first;
    else if (depth == 0) {
      answer.push_back({st,node.first});
      st = -1;
    }
  }
  
  return answer;
}

int main() {
  vector<vector<int>> input{
    {1,3},
    {3,6},
    {2,10},
    {3,10},
    {15,18}
  };
  auto output = mergeIntervals(input);
  for (auto row: output) {
    for (auto val: row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

//https://www.techiedelight.com/sort-vector-pairs-cpp/



