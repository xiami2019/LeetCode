/*
回溯法
*/
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (k < 0 || m <= 0 || n <= 0) return 0;
        bool visited[m*n];
        for (int i = 0; i < m*n; i++) {
            visited[i] = false;
        }
        int count = this->movingCountCore(k, m, n, 0, 0, visited);
        return count;
    }

    // 回溯算法核心
    int movingCountCore(int k, int m, int n, int startRow, int startCol, bool* visited) {
        int count = 0;
        if (check(k, m, n, startRow, startCol, visited)) {
            visited[startRow*n+startCol] = true;
            count = 1 + movingCountCore(k, m, n, startRow - 1, startCol, visited) + \
                        movingCountCore(k, m, n, startRow, startCol - 1, visited) + \
                        movingCountCore(k, m, n, startRow + 1, startCol, visited) + \
                        movingCountCore(k, m, n, startRow, startCol + 1, visited);
        }
        return count;
    }

    // check函数用来判断一个机器人能否进入一个方格
    bool check(int k, int rows, int cols, int row, int col, bool* visited) {
        if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= k && !visited[row*cols+col]) {
            return true;
        }
        return false;
    }

    // 得到一个数字的数位和
    int getDigitSum(int number) {
        int digitSum = 0;
        for (; number; digitSum += number % 10, number /= 10);
        return digitSum;
    }
};