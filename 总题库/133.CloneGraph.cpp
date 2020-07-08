/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// DFS，深度优先搜索
class Solution {
    map<Node*, Node*> visited; // 存储原节点到它的克隆节点的映射
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        if (visited.count(node)) return visited[node];
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return newNode;
    }
};

// BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL; // 空节点直接返回；
        map<Node*, Node*> visited; // 用来标记一个节点是否被访问，key值为原节点的地址，value值为克隆节点的地址；
        queue<Node*> q; // 用来进行广度优先搜索的队列；
        Node* newNode = new Node(node->val); // 建立新的初始节点；
        visited[node] = newNode; // 首先访问初始节点；
        q.push(node); // 将初始节点压入队列；

        while (!q.empty()) { // 进行广度优先搜索；
            Node* curNode = q.front();
            q.pop();
            for (Node* neighbor : curNode->neighbors) { // 迭代遍历每一个节点的临接链表，如果已经克隆过则直接加入克隆节点的临接链表中，否则克隆后压入队列
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curNode]->neighbors.push_back(visited[neighbor]);
            }
        }
        return newNode;
    }
};