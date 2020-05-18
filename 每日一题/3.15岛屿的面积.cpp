/*
法一：朴素DFS
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) return 0;
        int addX[4] = {0, 0, 1, -1};
        int addY[4] = {1, -1, 0, 0};
        int area = 0;
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++){
            area += dfs(grid, x + addX[i], y + addY[i]);
        }
        return 1 + area;
    }
};

/*
法二：朴素BFS
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    maxArea = max(maxArea, bfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int bfs(vector<vector<int>>& grid, int x, int y)
    {
        queue<pair<int, int> > nodes;
        nodes.push(make_pair(x, y));
        int addX[4] = {0, 0, 1, -1};
        int addY[4] = {1, -1, 0, 0};
        int area = 1;
        grid[x][y] = 0;
        while (!nodes.empty()){
            pair<int, int> temp = nodes.front();
            nodes.pop();
            x = temp.first, y = temp.second;
            for (int i = 0; i < 4; i++){
                int width = grid.size(), height = grid[0].size();
                int newX = x + addX[i], newY = y + addY[i];
                if (newX < 0 || newX >= width || newY < 0 || newY >= height || grid[newX][newY] == 0){
                    continue;
                }
                grid[newX][newY] = 0;
                nodes.push(make_pair(newX, newY));
                area++;
            }
        }
        return area;
    }
};

//DFS栈实现：
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i)
            for (int j = 0; j != grid[0].size(); ++j) {
                int cur = 0;
                stack<int> stacki;
                stack<int> stackj;
                stacki.push(i);
                stackj.push(j);
                while (!stacki.empty()) {
                    int cur_i = stacki.top(), cur_j = stackj.top();
                    stacki.pop();
                    stackj.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
                        continue;
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        stacki.push(next_i);
                        stackj.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        return ans;
    }
};