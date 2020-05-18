#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;
        for(char c : s){
            rows[currentRow] += c;
            if(currentRow == 0 || currentRow == numRows - 1){
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }
            
        string resultStr = "";
        for(string row: rows){
            resultStr += row;
        }
        return resultStr;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        //找规律
        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
