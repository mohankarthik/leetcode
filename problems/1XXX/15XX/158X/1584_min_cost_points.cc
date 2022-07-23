#include "../../../../common/Includes.h"

struct Point {
    int index;
    int x;
    int y;
    Point(int x, int y, int index): x(x), y(y), index(index) {}
};

struct Edge {
    Point *p1;
    Point *p2;
    int dist;
    Edge(Point *p1, Point *p2): p1(p1), p2(p2) {
        dist = abs(p1->x - p2->x) + abs(p1->y - p2->y);
    }
};

bool operator<(const Edge &lhs, const Edge &rhs) {
    return lhs.dist > rhs.dist;    
}

class DisjointSets {
public:
    DisjointSets(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void insert(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        const int n = pts.size();
        priority_queue<Edge> edges;
        
        vector<Point*> points;
        for (int i = 0; i < n; i++)
            points.emplace_back(new Point(pts[i][0], pts[i][1], i));
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                edges.push(Edge(points[i], points[j]));
            }
        }
        
        DisjointSets *ds = new DisjointSets(n);
        
        int answer = 0;
        int connectionsLeft = n-1;
        while(!edges.empty() and connectionsLeft) {
            const Edge edge = edges.top();
            edges.pop();
            if (!ds->connected(edge.p1->index, edge.p2->index)) {
                ds->insert(edge.p1->index, edge.p2->index);
                connectionsLeft--;
                answer += edge.dist;
            }
        }
        
        return answer;
        
    }
};