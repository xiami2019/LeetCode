/*
多源广度优先搜索
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int> > bfs;
        int row = grid.size(), column = grid[0].size();
        int maxDistance = INT_MIN;
        int addX[4] = {0, 0, 1, -1};
        int addY[4] = {1, -1, 0, 0};
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if (grid[i][j] == 1){
                    bfs.push(make_pair(i, j));
                }
            }
        }
        if (bfs.size() == 0 || bfs.size() == row * column) return -1;

        while (!bfs.empty()){
            pair<int, int> temp = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; i++){
                int newX = temp.first + addX[i], newY = temp.second + addY[i];
                if (newX >= 0 && newX < row && newY >= 0 && newY < column){
                    if (grid[newX][newY] == 0){
                        grid[newX][newY] = grid[temp.first][temp.second] + 1;
                        maxDistance = max(maxDistance, grid[newX][newY]);
                        bfs.push(make_pair(newX, newY));
                    }
                }
            }
        }
        return maxDistance - 1;
    }
};

/*
多源最短路Dijkstra算法
*/
class Solution{
public:
    static constexpr int MAX_N = 100 + 5;
    static constexpr int INF = int(1E6);
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int n;
    int d[MAX_N][MAX_N];

    struct Status {
        int v, x, y;
        bool operator < (const Status &rhs) const {
            return v > rhs.v;
        }
    };

    priority_queue <Status> q;

    int maxDistance(vector<vector<int> > &grid){
        this->n = grid.size();
        auto &a = grid;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                d[i][j] = INF;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[i][j]) {
                    d[i][j] = 0;
                    q.push({0, i, j});
                }
            }
        }

        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            for (int i = 0; i < 4; i++){
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1)) continue;
                if (f.v + 1 < d[nx][ny]){
                    d[nx][ny] = f.v + 1;
                    q.push({d[nx][ny], nx, ny});
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!a[i][j]) ans = max(ans, d[i][j]);
            }
        }

        return (ans == INF) ? -1 : ans;
    }
};

/*
动态规划
*/
class Solution {
public:
    static constexpr int MAX_N = 100 + 5;
    static constexpr int INF = int(1E6);
    
    int f[MAX_N][MAX_N];
    int n;

    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        vector<vector<int>>& a = grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = (a[i][j] ? 0 : INF);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) continue;
                if (i - 1 >= 0) f[i][j] = min(f[i][j], f[i - 1][j] + 1);
                if (j - 1 >= 0) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (a[i][j]) continue;
                if (i + 1 < n) f[i][j] = min(f[i][j], f[i + 1][j] + 1);
                if (j + 1 < n) f[i][j] = min(f[i][j], f[i][j + 1] + 1);
            }
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, f[i][j]);
                }
            }
        }

        if (ans == INF) return -1;
        else return ans;
    }
};