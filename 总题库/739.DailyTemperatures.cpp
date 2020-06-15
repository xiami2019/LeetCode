// 使用单调栈的方法

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return res;
    }
};

// [73, 74, 75, 71, 69, 72, 76, 73]
// [1, 1, 4, 2, 1, 1, 0, 0]