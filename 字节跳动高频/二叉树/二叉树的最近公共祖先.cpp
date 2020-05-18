/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
递归写法
*/
class Solution {
    TreeNode* ans;

    int recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q) {
        if (currentNode == NULL) return false;
        int left, right, mid;
        left = this->recurseTree(currentNode->left, p, q);
        right = this->recurseTree(currentNode->right, p, q);
        mid = (currentNode == p || currentNode == q) ? 1 : 0;

        if (mid + left + right >= 2) {
            this->ans = currentNode;
        }

        return mid + left + right > 0;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->recurseTree(root, p, q);
        return this->ans;
    }
};

/*
父指针迭代：
每个节点都有父指针，那么可以从p和q回溯以获取它们的公共祖先。在这个遍历过程中，我们得到的第一个公共节点是LCA节点。
所以可以考虑在遍历树时将父指针保存在字典中。
算法：
1. 从根节点开始遍历树。
2. 在找到p和q之前，将父指针存储。
3. 一旦我们找到了p和q，我们就可以使用父指针字典获得p的所有祖先，并添加到一个称为祖先的结合中
4. 同样，我们遍历节点q的祖先。如果祖先存在于为p设置的祖先中，这意味着这是p和q之间的第一个公共祖先（同时向上遍历），因此这是LCA节点。
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Stack for tree traversal
        stack<TreeNode*> s;

        // Hashmap for parent pointers
        map<TreeNode*, TreeNode*> parent;

        parent[root] = NULL;
        s.push(root);

        // Iterate until we find both the nodes p and q
        while (parent.count(p) == 0 || parent.count(q) == 0) {
            TreeNode* node = s.top();
            s.pop();
            // While traversing the tree, keep saving the parent pointers
            if (node->left != NULL) {
                parent[node->left] = node;
                s.push(node->left);
            }
            if (node->right != NULL) {
                parent[node->right] = node;
                s.push(node->right);
            }
        }

        // Ancestors set() for node p
        set<TreeNode*> ancestors;

        // Process all ancestors for node p using parent pointers.
        while (p != NULL) {
            ancestors.insert(p);
            p = parent[p];
        }

        // The first ancestor of q which appears in
        // p's ancestor set() is their lowest common ancestor.
        while (ancestors.count(q) == 0) {
            q = parent[q];
        }
        return q;
    }
};

/*
方法三：无父指针的迭代
在前面的方法中，LCA 在回溯过程中被发现。但摆脱回溯过程本身也是可行的。在这种方法中，我们总是有一个指向可能 LCA 的指针，当我们能够同时找到这两个节点时，返回指针作为答案。
算法1：
1. 从根节点开始；
2. 将（root，root_state）放在栈上。root_state定义要遍历该节点的一个子节点还是两个子节点。
3. 当栈不为空时，查看栈的顶部元素，该元素表示为（parent_node, parent_state）
4. 在遍历parent_node的任何子节点之前，我们检查parent_node本身是否是p或q中的一个。
5. 当我们第一次找到p或q的时候，设置一个布尔标记，名为one_node_found为true。还可以通过在变量LCA_index中记录栈的顶部索引来跟踪最近的公共祖先。
   因为栈的所有当前元素都是我们刚刚发现的节点的祖先。
6. 第二次 parent_node == p or parent_node == q 意味着我们找到了两个节点，我们可以返回 LCA node 。
7. 每当我们访问 parent_node 的子节点时，我们将 (parent_node, updated_parent_state) 推到栈上。我们更新父级的状态为子级/分支已被访问/处理，并且相应地更改状态。
8. 当状态变为 BOTH_DONE 时，最终会从栈中弹出一个节点，这意味着左、右子树都被推到栈上并进行处理。如果 one_node_found 是 true 的，那么我们需要检查被弹出的顶部节点是否可能是找到的节点的祖先之一。在这种情况下，我们需要将 LCA_index 减一。因为其中一位祖先被弹出了。
当同时找到 p 和 q 时，LCA_index 将指向栈中包含 p 和 q 之间所有公共祖先的索引。并且 LCA_index 元素具有 p 和 q 之间的最近公共祖先。
*/
class Solution {
    // Three static flags to keep track of post-order traversal.
    // Both left and right traversal pending for a node.
    // Indicates the nodes children are yet to be traversed.
    int BOTH_PENDING = 2;
    // Left traversal done.
    int LEFT_DONE = 1;
    // Both left and right traversal done for a node.
    // Indicates the node can be popped off the stack.
    int BOTH_DONE = 0;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, int>> s;

        // Initialize the stack with the root node.
        s.push({root, this->BOTH_PENDING});

        // This flag is set when either one of p or q is found.
        bool one_node_found = false;

        // This is used to keep track of the LCA.
        TreeNode* LCA = NULL;

        // Child node
        TreeNode* childNode = NULL;

        // We do a post order traversal of the binary tree using stack
        while (!s.empty()) {
            auto [parentNode, parentState] = s.top();
            
            // If the parent_state is not equal to BOTH_DONE,
            // this means the parentNode can't be popped off yet.
            if (parentState != this->BOTH_DONE) {
                // If both child traversals are pending
                if (parentState == this->BOTH_PENDING) {
                    // Check if the current parentNode is either p or q.
                    if (parentNode == p || parentNode == q) {
                        // If one_node_found was set already, this means we have found both the nodes.
                        if (one_node_found) {
                            return LCA;
                        }
                        else {
                            // Otherwise, set one_node_found to True to mark one of p and q is found.
                            one_node_found = true;
                            // Save the current top element of stack as the LCA.
                            LCA = s.top().first;
                        }
                    }

                    // If both pendings, traverse the left child first
                    childNode = parentNode->left;
                }
                else {
                    // traverse right child
                    childNode = parentNode->right;
                }

                // Update the node state at the top of the stack
                // Since we have visited one more child.
                s.pop();
                s.push({parentNode, parentState - 1});

                // Add the child node to the stack for traversal.
                if (childNode != NULL) {
                    s.push({childNode, this->BOTH_PENDING});
                }
            }
            else {
                // If the parentState of the node is both done,
                // the top node could be popped off the stack.
                // Update the LCA node to be the next top node.
                if (LCA == s.top().first) {
                    s.pop();
                    if (one_node_found) {
                        LCA = s.top().first;
                    }
                }
                else {
                    s.pop();
                }
            }
        }
        return NULL;
    }
};