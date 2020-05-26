class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (popped.size() == 0 && pushed.size() == 0) return true;
        if (popped.size() == 0 || pushed.size() == 0) return false;
        
        int index = 0;
        stack<int> s;
        for (int i : pushed) {
            s.push(i);
            while (!s.empty() && s.top() == popped[index]) {
                s.pop();
                index++;
            }
        }
        return index == popped.size();
    }
};