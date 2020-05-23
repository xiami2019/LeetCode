class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int rows = matrix.size(), cols = matrix[0].size();
        int rightCol = cols - 1;
        int topRow = 0;
        while (topRow < rows && rightCol >= 0) {
            if (matrix[topRow][rightCol] == target) return true;
            if (matrix[topRow][rightCol] > target) {
                rightCol--;
                continue;
            }
            if (matrix[topRow][rightCol] < target) {
                topRow++;
                continue;
            }
        }
        return false;
    }
};