class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<int>();

        int rowsUp = 0, rowsBottom = matrix.size() - 1, colsLeft = 0, colsRight = matrix[0].size() - 1;
        int counts = matrix.size() * matrix[0].size(), index = 0;
        vector<int> ans(counts);
        while (true) {
            for (int col = colsLeft; col <= colsRight; col++) {
                ans[index++] = matrix[rowsUp][col];
            }
            rowsUp++;
            if (index == counts) break;

            for (int row = rowsUp; row <= rowsBottom; row++) {
                ans[index++] = matrix[row][colsRight];
            }
            colsRight--;
            if (index == counts) break;

            for (int col = colsRight; col >= colsLeft; col--) {
                ans[index++] = matrix[rowsBottom][col];
            }
            rowsBottom--;
            if (index == counts) break;

            for (int row = rowsBottom; row >= rowsUp; row--) {
                ans[index++] = matrix[row][colsLeft];
            }
            colsLeft++;
            if (index == counts) break;
        }
        return ans;
    }
};