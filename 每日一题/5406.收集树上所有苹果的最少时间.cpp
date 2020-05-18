class Solution {
    map<int, vector<int> > subNodes;
    int leastLength = 0;
    void dfs(int node, int len, vector<bool>& hasApple) {
        len++;
        for (int i : subNodes[node]) {
            if (hasApple[i]) {
                leastLength += (len * 2);
            }
            else {
                dfs(i, len, hasApple);
            }
        }
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int eddesNum = edges.size();
        if (eddesNum == 0 || edges.size() == 0) return 0;
        for (int i = 0; i < eddesNum; i++) {
            subNodes[edges[i][0]].push_back(edges[i][1]);
        }
        dfs(0, 0, hasApple);
        return leastLength;
    }
};