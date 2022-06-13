#include "../../../../common/Includes.h"

class Logger {
private:
    unordered_map<string,int> _nextAllowed;
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (_nextAllowed.count(message) == 0 or _nextAllowed[message] <= timestamp) {
            _nextAllowed[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */