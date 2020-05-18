/*
动态规划
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int preValue = 0;
                if (i - 1 >= 0) {
                    preValue = max(preValue, grid[i-1][j]);
                }
                if (j - 1 >= 0) {
                    preValue = max(preValue, grid[i][j-1]);
                }
                grid[i][j] += preValue;
            }
        }
        return grid[rows - 1][cols - 1];
    }
};

/*
要求不能修改原数组时
*/
class Solution {
public:
    int maxValue(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<int> preValues(cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j - 1 >= 0) {
                    preValues[j] = max(preValues[j - 1], preValues[j]) + gird[i][j];
                }
                else {
                    preValues[j] = gird[i][j] + preValues[j];
                }
            }
        }
        return preValues[cols - 1];
    }
};