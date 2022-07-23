#include "../../../../common/Includes.h"

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        const int n = tiles.size();
        
        int i = 0, j = 0;
        int answer = 0;
        int current = 0;
        
        while (i <= j and j < n) {
            if (tiles[i][0] + carpetLen > tiles[j][1]) {
                current += (tiles[j][1] - tiles[j][0] + 1);
                answer = max(answer, current);
                j++;
            } else {
                answer = max(answer, current + tiles[i][0] + carpetLen - tiles[j][0]);
                current -= (tiles[i][1] - tiles[i][0] + 1);
                i++;
            }
        }
        
        return answer;
    }
};