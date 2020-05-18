// 二维栈方法

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> mat(rows, vector<int>(cols));
        int maxRectangle = INT_MIN;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0) mat[i][j] = matrix[i][j] - '0';
                else {
                    mat[i][j] = matrix[i][j] == '0' ? 0 : mat[i - 1][j] + 1;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            stack<int> s;
            s.push(-1);
            for (int j = 0; j < cols; j++) {
                while (s.top() != -1 && mat[i][s.top()] >= mat[i][j]) {
                    int temp = mat[i][s.top()];
                    s.pop();
                    maxRectangle = max(maxRectangle, temp * (j - 1 - s.top()));
                }
                s.push(j);
            }
            while (s.top() != -1) {
                int temp = mat[i][s.top()];
                s.pop();
                maxRectangle = max(maxRectangle, temp * (cols - 1 - s.top()));
            }
        }

        return maxRectangle;
    }
};