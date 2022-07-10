#include "../../../../common/Includes.h"

class ZigzagIterator {
private:
    vector<int> array;
    vector<int>::iterator it;

    void initializeArray(const vector<vector<int>>& arrays) {
        vector<int> sizes;
        int n = arrays.size();
        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            sizes.push_back(arrays[i].size());
            maxSize = max(maxSize, sizes.back());
        }
        
        for (int i = 0; i < maxSize; i++)
            for (int j = 0; j < n; j++)
                if (i < sizes[j])
                    array.push_back(arrays[j][i]);
        
        it = array.begin();
    }
public:
    ZigzagIterator(const vector<int>& v1, const vector<int>& v2) {
        vector<vector<int>> temp_array;
        temp_array.push_back(v1);
        temp_array.push_back(v2);
        initializeArray(temp_array);
    }

    ZigzagIterator(const vector<vector<int>>& arrays) {
        initializeArray(arrays);
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != array.end();
    }
};

int main(void) {
    vector<int> input11 = {1}; vector<int> input12 = {};
    ZigzagIterator *op = new ZigzagIterator(input11, input12);
    cout << "[";
    while(op->hasNext()) {
        cout << op->next() << ",";
    }
    cout << "]" << endl;
    return 0;
}