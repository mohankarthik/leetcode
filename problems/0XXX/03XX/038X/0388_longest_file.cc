#include "../../../../common/Includes.h"

class Solution {
private:
    bool isFile(string input) {
        return input.find('.') != string::npos;
    }
    
    string getPath(const vector<string> &dirs) {
        string path = "";
        for (string dir: dirs) {
            path += dir + '/';
        }
        if (path != "")
            path.pop_back();
        return path;
    }
public:
    int lengthLongestPath(string input) {
        if (input == "")
            return 0;
        
        string curPath = "";
        vector<string> dirs;
        
        stringstream inputstream(input);
        string line;
        
        size_t maxLength = 0;
        
        while(std::getline(inputstream, line, '\n')) {
            int numTabs = count(line.begin(), line.end(), '\t');
            
            // Checks
            if (numTabs > dirs.size()) 
                return -1;
            
            // If the number of tabs has reduced, then set dirs to the right depth
            while (numTabs < dirs.size())
                dirs.pop_back();
            curPath = getPath(dirs);

            string actPath = line.substr(numTabs);
            
            if (isFile(line)) {
                const string temp = curPath 
                    + ((dirs.size() >= 1) ? "/" : "")
                    + actPath;
                maxLength = max(maxLength, temp.length());
            } else {
                dirs.push_back(actPath);
                if (dirs.size() > 1)
                    curPath += '/' + actPath;
                else 
                    curPath += actPath;
            }
        }
        
        return maxLength;
    }
};

int main(void) {
    Solution *sol = new Solution();
    sol->lengthLongestPath("dir\n\t        file.txt\n\tfile2.txt");
    return 0;
}