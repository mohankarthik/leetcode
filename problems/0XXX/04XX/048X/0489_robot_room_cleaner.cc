#include "../../../../common/Includes.h"

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
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

class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
 };

class Solution {
    Robot* _robot;
    unordered_set<pair<int,int>, hash_pair> _seen;
    const vector<vector<int>> _directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    // Turn 180, go back, and turn 180 again so we face the same direction as before
    void _goBack() {
        _robot->turnRight();
        _robot->turnRight();
        _robot->move();
        _robot->turnRight();
        _robot->turnRight();
    }
    
    void _backtrack(int row, int col, int dir) {
        // Mark current cell as seen and clean it
        _seen.insert({row,col});
        _robot->clean();
        
        // Move in all 4 directions
        for (int i = 0; i < 4; i++) {
            int newDir = (dir + i) % 4;
            int newRow = row + _directions[newDir][0];
            int newCol = col + _directions[newDir][1];
            
            // If we haven't seen the new cell & the robot is able to move & backtrack
            if (_seen.count({newRow, newCol}) == 0 and _robot->move()) {
                _backtrack(newRow, newCol, newDir);
                _goBack();
            }
            
            // Turn
            _robot->turnRight();
        }
    }
public:
    void cleanRoom(Robot& robot) {
        _robot = &robot;
        _backtrack(0,0,0);
    }
};