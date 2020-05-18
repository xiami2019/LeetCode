class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0 && popped.size() == 0) return true;
        if (pushed.size() == 0 || popped.size() == 0) return false;
        stack<int> auxiliary;
        int index = 0;
        for (int i : pushed) {
            auxiliary.push(i);
            while (!auxiliary.empty() && auxiliary.top() == popped[index]) {
                auxiliary.pop();
                index++;
            }
        }
        if (index == popped.size()) return true;
        else return false; // 如果已经压完了所有压入序列中的数字，但还没找到要弹出的数字，则不是弹出序列
    }
};