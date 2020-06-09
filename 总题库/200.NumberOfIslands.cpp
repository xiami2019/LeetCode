class Solution {
    int addX[4] = {0, 0, 1, -1};
    int addY[4] = {1, -1, 0, 0};

public:
    void dfs(vector<vector<char>>& grid, int x, int y, const int& rows, const int& cols) {
        for (int i = 0; i < 4; i++) {
            int newX = x + addX[i], newY = y + addY[i];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == '1') {
                grid[newX][newY] = '0';
                dfs(grid, newX, newY, rows, cols);
            }
        }
    }

    void bfs(vector<vector<char>>& grid, int x, int y, const int& rows, const int& cols) {
        queue<pair<int, int>> q({{x, y}});
        while (!q.empty()) {
            auto [curX, curY] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = curX + addX[i], newY = curY + addY[i];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == '1') {
                    grid[newX][newY] = '0';
                    q.push({newX, newY});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // 检查输入的grid不合法的情况；
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int islandsNumber = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++islandsNumber;
                    grid[i][j] = '0';
                    // dfs(grid, i, j, rows, cols);
                    bfs(grid, i, j, rows, cols);
                }
            }
        }
        return islandsNumber;
    }
};

// 并查集
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        this->count = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * cols + j);
                    this->count++;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) { // 路径压缩
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            }
            else if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            }
            else {
                parent[rooty] = rootx;
                rank[rootx] += 1;
            }
            this->count--;
        }
    }

    int getCount() {
        return this->count;
    }

private:
    int count;
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int rows = grid.size(), cols = grid[0].size();
        int islandsNum = 0;
        UnionFind uf(grid);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                        uf.unite(r * cols + c, (r - 1) * cols + c);
                    }
                    if (r + 1 < rows && grid[r + 1][c] == '1') {
                        uf.unite(r * cols + c, (r + 1) * cols + c);
                    }
                    if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                        uf.unite(r * cols + c, r * cols + c - 1);
                    }
                    if (c + 1 < cols && grid[r][c + 1] == '1') {
                        uf.unite(r * cols + c, r * cols + c + 1);
                    }
                }
            }
        }
        return uf.getCount();
    }
};