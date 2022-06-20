#include "../../../../common/Includes.h"

class DetectSquares {
private:
    static const int MAX_POINTS = 1001;
    int numPoints[MAX_POINTS][MAX_POINTS];
    vector<pair<int,int>> records;
    
public:
    DetectSquares() {
        memset(numPoints, 0, sizeof(numPoints));
    }
    
    void add(vector<int> point) {
        numPoints[point[0]][point[1]]++;
        records.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        const int x1 = point[0], y1 = point[1];
        int answer = 0;
        for (auto [x3, y3]: records) {
            if (abs(x1 - x3) == abs(y1 - y3) and abs(x1 - x3) > 0) {
                answer += numPoints[x1][y3] * numPoints[x3][y1];
            }
        }
        return answer;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */