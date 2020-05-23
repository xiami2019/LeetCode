class Solution {
    int cells = 0;
    int addX[4] = {1, -1, 0, 0};
    int addY[4] = {0, 0, 1, -1};
    int getDigitalSum(int x, int y){
        int res = 0;
        while (x || y) {
            if (x){
                res += x % 10;
                x /= 10;
            }
            if (y) {
                res += y % 10;
                y /= 10;
            }
        }
        return res;
    }

    void backtrack(vector<vector<int>>& visited, int m, int n, int k, int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int newX = x + addX[i], newY = y + addY[i];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && visited[newX][newY] == 0) {
                if (getDigitalSum(newX, newY) <= k) {
                    cells++;
                    visited[newX][newY] = 1;
                    backtrack(visited, m, n, k, newX, newY);
                }
            }
        }
    }

public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;
        cells++;
        backtrack(visited, m, n, k, 0, 0);
        return cells;
    }
};