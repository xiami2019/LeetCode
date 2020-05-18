/*
法一：使用辅助数组
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int> > matrixCopy;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            matrixCopy.emplace_back(matrix[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[j][n-1-i] = matrixCopy[i][j];
            }
        }
        return;
    }
};

/*
法二：原地旋转
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n+1) / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};
