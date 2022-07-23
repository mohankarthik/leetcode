#include "../../../../common/Includes.h"

class DisjointSets {
private:
    vector<int> root;
    vector<int> rank;
    int size;
    
public:
    DisjointSets(int size) {
        root = vector<int>(size);
        rank = vector<int>(size, 0);
        for (int i = 0; i < size; i++)
            root[i] = i;
        this->size = size;
    }
    
    int find(int a) {
        if (a == root[a])
            return a;
        return root[a] = find(root[a]);
    }
    
    void insert(int a, int b) {
        const int rootA = find(a);
        const int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                root[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                root[rootA] = rootB;
            } else {
                root[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
    
    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
};

class Solution {
private:
    bool _useDisjointSets(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSets *ds = new DisjointSets(n);
        for (auto const &edge: edges) {
            ds->insert(edge[0], edge[1]);
        }
        return ds->isConnected(source, destination);
    }
    
    
    vector<set<int>> adjacency;
    unordered_set<int> seen;
    bool _useDfs(int n, vector<vector<int>>& edges, int source, int destination) {
        adjacency = vector<set<int>>(n);
        for(auto const &edge: edges) {
            adjacency[edge[0]].insert(edge[1]);
            adjacency[edge[1]].insert(edge[0]);
        }
        
        seen.insert(source);
        //return _dfsRecurse(source, destination);
        return _bfs(source, destination);
    }
    
    bool _dfsRecurse(int source, int destination) {
        if (source == destination)
            return true;
        
        for(auto &neighbor: adjacency[source]) {
            if (seen.find(neighbor) != seen.end())
                continue;
            
            seen.insert(neighbor);
            if (_dfsRecurse(neighbor, destination))
                return true;
        }
        
        return false;
    }
    
    bool _bfs(int source, int destination) {
        queue<int> q;
        q.push(source);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == destination)
                return true;
            
            for (auto &neighbor: adjacency[curr]) {
                if (seen.find(neighbor) != seen.end())
                    continue;
                
                seen.insert(neighbor);
                q.push(neighbor);
            }
        }
        
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        return _useDfs(n, edges, source, destination);
    }
};