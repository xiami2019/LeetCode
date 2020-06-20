// 使用BFS对入度表进行搜索
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> allPrerequisites(numCourses); // 使用临接表存储无向图；
        vector<int> indegrees(numCourses); // 入度表，用来在拓扑排序中选出入度为0的节点；
        for (vector<int> tmp : prerequisites) { // 初始化入度表和临接表；
            indegrees[tmp[0]]++;
            allPrerequisites[tmp[1]].push_back(tmp[0]);
        }
        queue<int> q; // 用于进行广度优先搜索的队列q；
        for (int i = 0; i < indegrees.size(); i++) {
            // 将所有入度为0的节点加入队列中；
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int course = q.front(); // 获得当前队列头的课程；
            indegrees[course] = -1; // 在入度表中标记为-1，代表已经访问过这门课程；
            q.pop();
            numCourses--;
            for (int i = 0; i < allPrerequisites[course].size(); i++) {
                // 检查所有这门口的后序课程，将入度减一；
                indegrees[allPrerequisites[course][i]]--;
                if (indegrees[allPrerequisites[course][i]] == 0) {
                    // 如果入度为0则入队；
                    q.push(allPrerequisites[course][i]);
                }
            }
        }
        if (numCourses) return false; // 如果还有课没上完则返回false，如果所有课已经上完则返回true；
        else return true;
    }
};

// 使用DFS在无向图中找环
class Solution {
    bool dfs(int course, vector<vector<int>>& adjancy, vector<int>& flags) {
        if (flags[course] == -1) return true; // flags[course] == -1代表被别的路径访问过，所以不算成环；
        if (flags[course] == 1) return false; // flags[course] == 1代表被当前的路径访问过，说明找到了一个环；
        flags[course] = 1; // 表示被当前路径占用；
        for (int i = 0; i < adjancy[course].size(); ++i) { // 对当前节点的所有临接节点进行DFS搜索；
            if (!dfs(adjancy[course][i], adjancy, flags)) {
                return false;
            }
        }
        flags[course] = -1; // 结束当前路径的搜索，标志设为被其他路径占用。
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjancy(numCourses); // 使用临接表存储无向图；
        vector<int> flags(numCourses); // 标记一门课是否被访问过，用来找环；
        for (vector<int> tmp : prerequisites) { // 初始化临接表；
            adjancy[tmp[1]].push_back(tmp[0]); // 
        }
        for (int i = 0; i < numCourses; ++i) {
            // 从每个节点开始，尝试找到一个环；
            if (!dfs(i, adjancy, flags)) {
                // 如果找到一个环，则无法构成拓扑排序，返回false；
                return false;
            }
        }
        return true;
    }
};