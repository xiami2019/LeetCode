class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        int rowsUp = 0, rowsBottom = matrix.size() - 1, colsLeft = 0, colsRight = matrix[0].size() - 1;
        int counts = matrix.size() * matrix[0].size(), index = 0;
        while (1) {
            for (int i = colsLeft; i <= colsRight; i++) {
                ans.emplace_back(matrix[rowsUp][i]);
                index++;
            }
            if (index == counts) break;
            rowsUp++;

            for (int i = rowsUp; i <= rowsBottom; i++) {
                ans.emplace_back(matrix[i][colsRight]);
                index++;
            }
            if (index == counts) break;
            colsRight--;

            for (int i = colsRight; i >= colsLeft; i--) {
                ans.emplace_back(matrix[rowsBottom][i]);
                index++;
            }
            if (index == counts) break;
            rowsBottom--;

            for (int i = rowsBottom; i >= rowsUp; i--) {
                ans.emplace_back(matrix[i][colsLeft]);
                index++;
            }
            if (index == counts) break;
            colsLeft++;
        }

        return ans;
    }
};