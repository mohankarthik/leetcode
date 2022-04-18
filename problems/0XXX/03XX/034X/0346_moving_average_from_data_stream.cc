#include "../../../../common/Includes.h"

class MovingAverage {
private:
    queue<int> queue;
    double sum = 0.0;
    int queue_size = 0;
    int max_size;
public:
    MovingAverage(int size):max_size(size),sum(0) {}
    
    double next(int val) {
        sum += val;
        queue.push(val);
        int queue_size = queue.size();
        if (queue_size <= max_size)
            return sum / queue_size;
        else {
            sum -= queue.front();
            queue.pop();
            return sum / max_size;
        }
    }
};