class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<int>();
        int rows = matrix.size(), cols = matrix[0].size();
        int topRow = 0, leftCol = 0, bottomRow = rows - 1, rightCol = cols - 1;
        int counts = rows * cols;
        vector<int> res(counts);
        for (int k = 0; k < counts;) {
            for (int i = leftCol; i <= rightCol; i++) {
                res[k++] = matrix[topRow][i];
            }
            topRow++;
            if (k >= counts) break;
            for (int i = topRow; i <= bottomRow; i++) {
                res[k++] = matrix[i][rightCol];
            }
            rightCol--;
            if (k >= counts) break;
            for (int i = rightCol; i >= leftCol; i--) {
                res[k++] = matrix[bottomRow][i];
            }
            bottomRow--;
            if (k >= counts) break;
            for (int i = bottomRow; i >= topRow; i--) {
                res[k++] = matrix[i][leftCol];
            }
            leftCol++;
        }
        return res;
    }
};