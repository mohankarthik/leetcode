#include "../../../../common/Includes.h"

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

class State {
public:
    int row{};
    int col;
    int dist;
    int elim_left;
    vector<int> target;
    int estimation;

    State(int row, int col, int dist, int elim_left, vector<int>& target): 
        row(row), col(col), dist(dist), elim_left(elim_left), target(target) {
            int manhattanDistance = target[0] - row + target[1] - col;
            this->estimation = manhattanDistance + this->dist;
        }
};

struct state_comparator
{
    bool operator()(const State& lhs, const State& rhs) const
    {
        if (lhs.estimation == rhs.estimation)
            return lhs.elim_left < rhs.elim_left;
        return lhs.estimation > rhs.estimation;
    }
};

ostream& operator<<(std::ostream &strm, const State &a) {
  return strm << "State(" << a.row << ", " << a.col << ", " << a.dist << ", " << a.elim_left << ", " << a.estimation << ")";
}

class Solution {
private:
    const vector<vector<int>> dfs = {{-1,0},{1,0},{0,-1},{0,1}};
    int n, m;
    unordered_map<pair<int,int>, int, hash_pair> seen;
    
    bool _isValid(int row, int col, int elim_left) {
        return (
            row >= 0 and row < n 
            and col >= 0 and col < m
            and (seen.count({row,col}) == 0 or seen[{row,col}] < elim_left)
        );
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        priority_queue<State, vector<State>, state_comparator> q;
        
        n = grid.size();
        m = grid[0].size();
        vector<int> target {n-1, m-1};
        
        q.push(State(0,0,0,k,target));
        seen[{0,0}] = 0;
        
        while(!q.empty()) {
            auto curr = q.top();
            q.pop();
            cout << curr << endl;
            
            // If we've reached the destination
            if (curr.row == n-1 and curr.col == m-1)
                return curr.dist;

            // Check if we can steamroll to our destination
            if (curr.estimation - curr.dist <= curr.elim_left)
                return curr.estimation;
            
            // if we've hit an obstacle
            if (grid[curr.row][curr.col] == 1) {
                if (curr.elim_left)
                    curr.elim_left--;
                else
                    continue;
            }
            
            for (auto df: dfs) {
                if (_isValid(curr.row+df[0], curr.col+df[1], curr.elim_left)) {
                    seen[{curr.row+df[0], curr.col+df[1]}] = curr.elim_left;
                    q.push(State(curr.row+df[0], curr.col+df[1], curr.dist+1, curr.elim_left, target));
                }
            }
        }
        
        return -1;
    }
};

int main(void)
{
    Solution *sol = new Solution();
    vector<vector<int>> grid1 {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    assert(sol->shortestPath(grid1, 1) == 6);
    vector<vector<int>> grid2 {{0,1,1},{1,1,1},{1,0,0}};
    assert(sol->shortestPath(grid2, 1) == -1);
}