// 使用BFS对入度表进行搜索
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> allPrerequisites(numCourses);
        vector<int> indegrees(numCourses);
        for (vector<int> tmp : prerequisites) {
            indegrees[tmp[0]]++;
            allPrerequisites[tmp[1]].push_back(tmp[0]);
        }
        queue<int> q;
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int course = q.front();
            indegrees[course] = -1;
            q.pop();
            numCourses--;
            for (int i = 0; i < allPrerequisites[course].size(); i++) {
                indegrees[allPrerequisites[course][i]]--;
                if (indegrees[allPrerequisites[course][i]] == 0) {
                    q.push(allPrerequisites[course][i]);
                }
            }
        }
        if (numCourses) return false;
        else return true;
    }
};

// 使用DFS在无向图中找环
class Solution {
    bool dfs(int course, vector<vector<int>>& adjancy, vector<int>& flags) {
        if (flags[course] == -1) return true;
        if (flags[course] == 1) return false;
        flags[course] = 1;
        for (int i = 0; i < adjancy[course].size(); ++i) {
            if (!dfs(adjancy[course][i], adjancy, flags)) {
                return false;
            }
        }
        flags[course] = -1;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjancy(numCourses);
        vector<int> flags(numCourses);
        for (vector<int> tmp : prerequisites) {
            adjancy[tmp[1]].push_back(tmp[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, adjancy, flags)) {
                return false;
            }
        }
        return true;
    }
};