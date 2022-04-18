#include "../common/Includes.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int i = 0;
        string result = "";
        while(i < a.size() && i < b.size()) {
            int v = (a[i] - '0' + b[i] - '0') + c;
            if (v >= 2) { 
                c = 1;
                v -= 2;
            } else {
                c = 0;
            }
            result += v + '0';
            cout << i << ' ' << a[i] << ' ' << b[i] << ' ' << result << endl;
            i++;
        }
        while(i < a.size()) {
            int v = a[i] - '0' + c;
            if (v >= 2) {
                c = 1;
                v -= 2;
            } else {
                c = 0;
            }
            result += v + '0';
            i++;
        }
        while(i < b.size()) {
            int v = b[i] - '0' + c;
            if (v >= 2) {
                c = 1;
                v -= 2;
            } else {
                c = 0;
            }
            result += v + '0';
            i++;
        }
        if (c != 0) result += '1';
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};