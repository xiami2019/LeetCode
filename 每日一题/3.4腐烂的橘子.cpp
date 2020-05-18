    /*
    思路：枚举+bfs；
    使用一个辅助二维数组用来记录橘子是在第几分钟腐烂的；
    先遍历一遍地图，存下来开始时所有腐烂橘子的坐标；
    以每个腐烂的橘子的位置为起点，开始进行bfs，如果碰到已经腐烂的橘子，但是腐烂的时间却大于当前
    时间+1，则需要更新该位置上橘子的腐烂时间；
    对所有起点进行bfs了之后，再次遍历地图，检查是否还有完好的橘子，以及所需要的时间是多少；
    */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int> > decaiedTime;
        vector<pair<int, int> > decaiedOrange;
        int maxTime = INT_MIN;
        for (int i = 0; i < grid.size(); i++){
            decaiedTime.push_back(vector<int>());
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2){
                    decaiedTime[i].push_back(0);
                    decaiedOrange.push_back(make_pair(i, j));
                }
                else{
                    decaiedTime[i].push_back(0);
                }
            }
        }

        for (int i = 0; i < decaiedOrange.size(); i++){
            this->bfs(decaiedOrange[i], grid, decaiedTime);
        }

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    return -1;
                }
                else{
                    maxTime = max(maxTime, decaiedTime[i][j]);
                }
            }
        }

        return maxTime;
    }

    void bfs(pair<int, int> start, vector<vector<int> >& grid, vector<vector<int> >& decaiedTime)
    {
        queue<pair<int, int> > bfsQueue;
        bfsQueue.push(start);
        
        int addX[4] = {0, 0, 1, -1};
        int addY[4] = {1, -1, 0, 0};
        int width = grid.size();
        int height = grid[0].size();

        while (!bfsQueue.empty()){
            int currentX = bfsQueue.front().first;
            int currentY = bfsQueue.front().second;
            int currentTime = decaiedTime[currentX][currentY];
            bfsQueue.pop();
            for (int i = 0; i < 4; i++){
                int newX = currentX + addX[i];
                int newY = currentY + addY[i];
                if (newX < 0 || newX >= width || newY < 0 || newY >= height){
                    continue;
                }
                else if (grid[newX][newY] == 1 || (grid[newX][newY] == 2 && decaiedTime[newX][newY] > currentTime + 1)){
                    grid[newX][newY] = 2;
                    bfsQueue.push(make_pair(newX, newY));
                    decaiedTime[newX][newY] = currentTime + 1;
                }
            }
        }
    }
};

/*
方法二：多源广度优先搜索：
思路：跟踪每个节点的层数，然后在BFS的时候保持实时的更新即可。
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int> > decaiedTime;
        vector<pair<int, int> > decaiedOrange;
        int maxTime = INT_MIN;
        for (int i = 0; i < grid.size(); i++){
            decaiedTime.push_back(vector<int>());
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2){
                    decaiedTime[i].push_back(0);
                    decaiedOrange.push_back(make_pair(i, j));
                }
                else{
                    decaiedTime[i].push_back(0);
                }
            }
        }

        this->bfs(decaiedOrange, grid, decaiedTime);

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    return -1;
                }
                else{
                    maxTime = max(maxTime, decaiedTime[i][j]);
                }
            }
        }

        return maxTime;
    }

    void bfs(vector<pair<int, int> > decaiedOrange, vector<vector<int> >& grid, vector<vector<int> >& decaiedTime)
    {
        queue<pair<int, int> > bfsQueue;
        int decaiedOrangeLen = decaiedOrange.size();
        for (int i = 0; i < decaiedOrangeLen; i++){
            bfsQueue.push(decaiedOrange[i]);
        }
        
        int addX[4] = {0, 0, 1, -1};
        int addY[4] = {1, -1, 0, 0};
        int width = grid.size();
        int height = grid[0].size();

        while (!bfsQueue.empty()){
            int currentX = bfsQueue.front().first;
            int currentY = bfsQueue.front().second;
            int currentTime = decaiedTime[currentX][currentY];
            bfsQueue.pop();
            for (int i = 0; i < 4; i++){
                int newX = currentX + addX[i];
                int newY = currentY + addY[i];
                if (newX < 0 || newX >= width || newY < 0 || newY >= height){
                    continue;
                }
                else if (grid[newX][newY] == 1 || (grid[newX][newY] == 2 && decaiedTime[newX][newY] > currentTime + 1)){
                    grid[newX][newY] = 2;
                    bfsQueue.push(make_pair(newX, newY));
                    decaiedTime[newX][newY] = currentTime + 1;
                }
            }
        }
    }
};

/*
标准参考代码：
*/
class Solution{
    int cnt; // 统计腐烂的橘子的个数；
    int dis[10][10]; //用来统计层数
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};
public:
    int orangesRotting(vector<vector<int> > &grid) {
        queue<pair<int, int> > Q;
        memset(dis, -1, sizeof(dis));
        cnt = 0;
        int n = (int)grid.size(), m = (int)grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    Q.push(make_pair(i, j));
                    dis[i][j] = 0;
                }
                else if (grid[i][j] == 1){
                    cnt += 1; // 腐烂的橘子个数+1；
                }
            }
        }

        while (!Q.empty()){
            pair<int, int> x = Q.front(); //广搜得到队列保证了先后顺序。
            Q.pop();
            for (int i = 0; i < 4; i++){
                int tx = x.first + dir_x[i];
                int ty = x.second + dir_y[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || ~dis[tx][ty] || !grid[tx][ty]){
                    continue;
                }
                dis[tx][ty] = dis[x.first][x.second] + 1;
                Q.push(make_pair(tx, ty));
                if (grid[tx][ty] == 1){
                    cnt -= 1;
                    ans = dis[tx][ty];
                    if (!cnt) break;
                }
            }
        }
        return cnt ? -1 : ans;
    }
};