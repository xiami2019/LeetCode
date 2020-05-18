/*
方法一：多源广度优先搜索
对于矩阵中的每一个元素，如果它的值为0，那么离它最近的0就是它自己。如果它的值为1，那么我们就需要找出离它最近的0，
并且返回这个距离值。

可以从0的位置开始进行广度优先搜索。广度优先搜索可以找到从起点到其余所有点的最短距离，因此如果我们从0开始搜索，每
次搜索到一个1，就可以得到0到这个1的最短距离。
*/
class Solution {
    int addX[4] = {0, 0, 1, -1};
    int addY[4] = {1, -1, 0, 0};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols));
        vector<vector<int> > seen(rows, vector<int>(cols));
        queue<pair<int, int> > bfs;
        // 将所有的0添加进初始队列中
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    bfs.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // 多源广度优先搜索
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; i++) {
                int newX = x + addX[i], newY = y + addY[i];
                if (newX < 0 || newX >= rows || newY < 0 || newY >= cols || seen[newX][newY] == 1) continue;
                dist[newX][newY] = dist[x][y] + 1;
                bfs.emplace(newX, newY);
                seen[newX][newY] = 1;
            }
        }
        return dist;
    }
};

/*
方法二：动态规划
对于矩阵中的任意一个1以及一个0，我们如何从这个1到达0并且距离最短呢？根据上面的做法，我们可以从1开始，先在
水平方向移动，再在竖直方向上移动，直到到达0的位置。这样一来，从一个固定的1走到任意一个0，在距离最短的前提
下可能有四种方法：
水平左、竖直上；
水平左、竖直下；
水平右、竖直上；
水平右、竖直下；
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        // 初始化动态规划数组，所有的距离值都设置为一个很大的数
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX / 2));
        // 如果(i, j)元素为0，则距离为0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                }
            }
        }
        // 只有水平向左移动和竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                if (i + 1 < rows) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < cols) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;
    }
};