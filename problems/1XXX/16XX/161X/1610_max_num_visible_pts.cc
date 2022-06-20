#include "../../../../common/Includes.h"

#define PI 3.14159265
#define MARGIN 1e-6

class Solution {
private:
    double findAngle(int x1, int x2, int y1, int y2) {
        return atan2((y2 - y1), (x2 - x1)) * 180.0 / PI;
    }
    
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> half_angles;
        int overlap = 0;
        for(auto &point: points) {
            if (point[0] == location[0] and point[1] == location[1]) {
                overlap++;
            } else {
                const double angleBetween = findAngle(point[0], location[0], point[1], location[1]);
                half_angles.emplace_back(angleBetween < 0 ? angleBetween + 360 : angleBetween);
            }
        }
        
        sort(half_angles.begin(), half_angles.end());
        vector<double> angles = half_angles;
        angles.insert(angles.end(), half_angles.begin(), half_angles.end());
        for (int i = half_angles.size(); i < angles.size(); i++) angles[i] += 360.0;
        
        const int n = angles.size();
        int i = 0, j = 0;
        int answer = 0;
        while (i <= j and j < n) {
            if ((angles[j] - angles[i]) <= angle + MARGIN) {
                j++;
            } else {
                answer = max(answer, j-i);
                i++;
            }
        }
        
        return max(answer, j-i) + overlap;
    }
};

int main(void) {
    Solution *sol = new Solution();
    vector<vector<int>> input1 {{2,1},{2,2},{3,3}};
    vector<int> location1 {1,1};
    assert(sol->visiblePoints(input1, 90, location1) == 3);
    vector<vector<int>> input2 {{2,1},{2,2},{3,4},{1,1}};
    vector<int> location2 {1,1};
    assert(sol->visiblePoints(input2, 90, location2) == 4);
    vector<vector<int>> input3 {{1,0},{2,1}};
    vector<int> location3 {1,1};
    assert(sol->visiblePoints(input3, 13, location3) == 1);
    vector<vector<int>> input4 {{0,0},{0,2}};
    vector<int> location4 {1,1};
    assert(sol->visiblePoints(input4, 90, location4) == 2);
}