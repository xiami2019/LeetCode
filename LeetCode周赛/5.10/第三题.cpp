class Solution {
    unordered_map<int, vector<int> > nodes;
    bool hasApplehelper(int idx, vector<bool>& hasApple) {
        bool selfOrChildHasApple = hasApple[idx];
        for (auto & node : nodes[idx]) {
            selfOrChildHasApple = this->hasApplehelper(node, hasApple) || selfOrChildHasApple;
        }
        if (!selfOrChildHasApple) {
            nodes.erase(idx);
        }
        return selfOrChildHasApple;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (auto & edge : edges) {
            nodes[edge[0]].emplace_back(edge[1]);
        }
        this->hasApplehelper(0, hasApple);

        return nodes.empty() ? 0 : 2 * (nodes.size() - 1);
    }
};