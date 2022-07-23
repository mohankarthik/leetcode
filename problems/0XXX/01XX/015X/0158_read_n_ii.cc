#include "../../../../common/Includes.h"

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    queue<char> q;

    int read4(char buf[4]) {
        // TODO
    }

public:
    Solution() {
        q = queue<char>();
    }
    
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        while(q.size() < n) {
            char temp[4];
            int numRead = read4(temp);
            if (numRead == 0) {
                break;
            }
            for (int i = 0; i < numRead; i++)
                q.push(temp[i]);
        }
        
        int numWritten = 0;
        while(!q.empty() and numWritten < n) {
            buf[numWritten] = q.front();
            q.pop();
            numWritten++;
        }
        return numWritten;
    }
};