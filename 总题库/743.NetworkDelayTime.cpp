class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int graph[N + 1][N + 1];
        for (int i = 0; i < N + 1; ++i) {
            for (int j = 0; j < N + 1; ++j) {
                graph[i][j] = INT_MAX;
            }
        }

        for (vector<int> triple : times) {
            graph[triple[0]][triple[1]] = triple[2];
        }
        vector<int> dist(N + 1, INT_MAX);
        vector<bool> seen(N + 1, false);
        dist[K] = 0;
        
        while (1) {
            int curNode = -1;
            int curDist = INT_MAX;
            for (int i = 1; i < N + 1; ++i) {
                if (!seen[i] && dist[i] < curDist) {
                    curNode = i;
                    curDist = dist[i];
                }
            }
            if (curNode == -1) {
                break;
            }
            seen[curNode] = true;
            for (int i = 1; i < N + 1; i++) {
                if (graph[curNode][i] < INT_MAX) {
                    dist[i] = min(dist[i], dist[curNode] + graph[curNode][i]);
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i < dist.size(); ++i){
            if (dist[i] > ans) {
                ans = dist[i];
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// 优先队列实现
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        typedef pair<int, int> PII;
        vector<bool> seen(N + 1, false); // 用来标记一个节点是否被访问过
        vector<int> dist(N + 1, INT_MAX); // 距离起始点的最短距离
        unordered_map<int, vector<PII>> graph; // 使用临接表来保存图
        priority_queue<PII, vector<PII>, greater<PII>> heap; // 小顶堆；维护到起始点的最短距离和点

        for (auto &t: times) {
            // 初始化临接表
            graph[t[0]].push_back({t[2], t[1]});
        }

        heap.push({0, K});
        dist[K] = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int curdist = t.first, curNode = t.second;
            if (seen[curNode]) continue;
            seen[curNode] = true;
            for (auto &p: graph[curNode]) {
                if (dist[p.second] > curdist + p.first) {
                    dist[p.second] = curdist + p.first;
                    heap.push({dist[p.second], p.second});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

// floyd-worshall算法
// Dj只能求出一个指定点到其他的最短路，floyd可以求出任意两点之间的最短路；
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> d(N+1, vector<int>(N+1, INF));
        for (int i = 1; i<=N; i++) d[i][i] = 0;

        for (auto &t: times){
            d[t[0]][t[1]] = min(d[t[0]][t[1]], t[2]);
        }

        for (int k = 1; k<=N; k++){
            for (int i = 1; i<=N; i++){
                for (int j =1; j<=N; j++){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int ans = 0;
        for (int i =1; i<=N; i++){
            ans = max(ans, d[K][i]);
        }
        return ans > INF/2 ? -1: ans;
    }
};