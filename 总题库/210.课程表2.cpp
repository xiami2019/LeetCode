// 拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preCourses(numCourses, vector<int>(numCourses, 0));
        vector<int> ans;
        vector<int> preCoursesCounts(numCourses, 0);
        for (auto &item : prerequisites) {
            preCourses[item[0]][item[1]] = 1;
            preCoursesCounts[item[0]]++;
        }
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < numCourses; i++) {
                if (preCoursesCounts[i] == 0) {
                    flag = true;
                    preCoursesCounts[i] = -1;
                    ans.push_back(i);
                    for (int j = 0; j < numCourses; j++) {
                        if (preCourses[j][i] == 1) {
                            preCourses[j][i] = 0;
                            preCoursesCounts[j]--;
                        }
                    }
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};

// DFS实现拓扑排序
// 深度优先搜索使用的是逆向思维
class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成；
    vector<int> visited;
    //用数组来模拟栈，下标0为栈底，n-1为栈顶
    vector<int> result;
    // 判断有向图中是否有环
    bool invalid;

public:
    void dfs(int u) {
        // 将节点标记为搜索中
        visited[u] = 1;
        // 搜索其相邻节点
        // 只要发现有环，立刻停止搜索
        for (int v: edges[u]) {
            // 如果未搜索那么搜索相邻节点
            if (visited[v] == 0) {
                dfs(v);
                if (invalid) {
                    return;
                }
            }

            else if (visited[v] == 1) {
                invalid = true;
                return;
            }
        }
        // 将节点标记为已完成
        visited[u] = 2;
        // 将节点入栈
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        // 每次挑选一个未搜索的节点，开始进行深度优先搜素
        for (int i = 0; i < numCourses && !invalid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (invalid) {
            return {};
        }
        // 如果没有环，那么就有拓扑排序
        // 如果下标0为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
};

// BFS实现拓扑排序
// BFS使用的是正向思维
class Solution{
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indeg;
    // 存储答案
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // 将所有入度为0的节点放入队列中
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // 从队首取出一个节点
            int u = q.front();
            q.pop();
            // 放入答案中
            result.push_back(u);
            for (int v : edges[u]) {
                --indeg[v];
                // 如果相邻节点v的入度为0，就可以选v对应的课程了
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (result.size() != numCourses) {
            return {};
        }
        return result;
    }
};