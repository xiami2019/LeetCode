struct Node{
    int i, j, h;
    Node(int x, int y, int z):i(x), j(y), h(z){}
    bool operator < (const Node& b) const {
        if (h > b.h) return true;
        return false;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0 || heightMap[0].size() == 0) {
            return 0;
        }
        int rows = heightMap.size(), cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // visited数组，用来标记某个节点是否被访问；
        priority_queue<Node> pq; // 优先队列，用来维护围墙边界；
        int ans = 0; // 用来储存结果；

        // 首先存入最外层边界，然后依此往里面缩小；
        for (int i = 0; i < rows; ++i) {
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, cols - 1, heightMap[i][cols - 1]});
            visited[i][0] = true;
            visited[i][cols - 1] = true;
        }
        for (int i = 0; i < cols; ++i) {
            pq.push({0, i, heightMap[0][i]});
            pq.push({rows - 1, i, heightMap[rows - 1][i]});
            visited[0][i] = true;
            visited[rows - 1][i] = true;
        }
        
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = cur.i + dirs[i], newY = cur.j + dirs[i + 1];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && visited[newX][newY] == false) {
                    if (cur.h > heightMap[newX][newY]) {
                        // 围墙高度大于相邻围墙的高度，可以灌水；
                        ans += cur.h - heightMap[newX][newY];
                        heightMap[newX][newY] = cur.h;
                    }
                    pq.push({newX, newY, heightMap[newX][newY]});
                    visited[newX][newY] = true;
                }
            }
        }
        return ans;
    }
};