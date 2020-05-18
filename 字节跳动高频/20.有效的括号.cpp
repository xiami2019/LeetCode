class Solution {
public:
    bool isValid(string s) {
        if (s == "") return true;
        stack<char> symbols;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                symbols.push(c);
            }
            else {
                if (symbols.empty()) return false;
                if ((symbols.top() == '(' && c == ')') || (symbols.top() == '[' && c == ']') || (symbols.top() == '{' && c == '}')){
                    symbols.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (symbols.empty()) return true;
        else return false;
    }
};