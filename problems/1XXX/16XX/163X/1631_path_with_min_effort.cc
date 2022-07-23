#include "../../../../common/Includes.h"

struct Point {
    int x;
    int y;
    
    Point(int x, int y): x(x), y(y) {}
    
    bool operator==(const Point &other) const
    { 
        return (x == other.x and y == other.y);
    }
};

class PointHashFunction {
public:
    size_t operator()(const Point& p) const
    {
        return (p.x * 101) + p.y;
    }
};

struct Cell {
    Point p;
    int maxClimb;
    
    Cell(int x, int y, int maxClimb): p(Point(x,y)), maxClimb(maxClimb) {}
};

ostream& operator<< (ostream &out, const Cell &cell) {
    out << "(" << cell.p.x << "," << cell.p.y << ") -> " << cell.maxClimb;
    return out;
}

struct Comparator {
    bool operator()(Cell const &c1, Cell const &c2) {
        return c2.maxClimb < c1.maxClimb;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int n = heights.size();
        const int m = heights[0].size();
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        unordered_set<Point, PointHashFunction> seen;
        priority_queue<Cell, vector<Cell>, Comparator> pq;
        
        pq.push(Cell(0,0,0));
        while(!pq.empty()) {
            const auto curr = pq.top();
            pq.pop();
            
            const int x = curr.p.x;
            const int y = curr.p.y;
            const int val = curr.maxClimb;
            
            //cout << curr << endl;
            
            if (seen.find(curr.p) != seen.end()) continue;
            if (x == n-1 and y == m-1) return val;
            seen.insert(curr.p);
            
            for (auto const &dir: directions) {
                const int newX = x + dir[0];
                const int newY = y + dir[1];
                if (newX < 0 or newX >= n or newY < 0 or newY >= m) continue;
                
                const int diff = max(val, abs(heights[newX][newY] - heights[x][y]));
                pq.push(Cell(newX, newY, diff));
            }
        }
        
        return -1;
    }
};