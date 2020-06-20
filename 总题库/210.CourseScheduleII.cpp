// 拓扑排序可以用BFS或者DFS来处理；
// 在BFS的过程中记录路径；
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacency(numCourses, vector<int>({}));
        vector<int> inDegrees(numCourses, 0);
        vector<int> res;
        for (vector<int>& temp : prerequisites) {
            inDegrees[temp[0]]++;
            adjacency[temp[1]].push_back(temp[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curCourse = q.front();
            res.push_back(curCourse);
            q.pop();
            for (int i = 0; i < adjacency[curCourse].size(); ++i) {
                inDegrees[adjacency[curCourse][i]]--;
                if (inDegrees[adjacency[curCourse][i]] == 0) {
                    q.push(adjacency[curCourse][i]);
                }
            }
        }
        if (res.size() != numCourses) {
            return {};
        }
        else return res;
    }
};