// 并查集
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind() {
        parent.resize(26);
        rank.resize(26);
        // iota函数对一个范围数据进行赋值, 从第三个参数，依此往后赋值；
        iota(parent.begin(), parent.end(), 0);
        iota(rank.begin(), rank.end(), 0);
    }

    // 并查集的核心步骤，寻找一个点所属连通集的根节点；
    int find(int index) { // 找index所属连通集的根节点；
        if (index == parent[index]) {
            // 此时说明index是它当前所属连通集的根节点；
            return index;
        }
        parent[index] = find(parent[index]);
        return parent[index];
    }

    // 将index1和index2连通；
    void unite(int index1, int index2) {
        int root1 = find(index1);
        int root2 = find(index2);
        
        if (root1 != root2) {
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            }
            else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            }
            else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf; // 先构造一个空的连通集
        for (const string & str : equations) {
            if (str[1] == '=') {
                // 先将所有等式构造成连通集；
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                uf.unite(index1, index2);
            }
        }
        for (const string & str : equations) {
            if (str[1] == '!') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                if (uf.find(index1) == uf.find(index2)) {
                    return false;
                }
            }
        }
        return true;
    }
};