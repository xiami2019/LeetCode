class Solution {
    bool ifBinarySearchTree(vector<int>& postorder, int low, int high) {
        if (high - low <= 1) return true;
        int root = postorder[high];
        int index = low;
        for (; postorder[index] < root; index++);
        for (int i = index; i < high; i++) {
            if (postorder[i] < root) return false;
        }
        // 判断左子树和是否是二叉搜索树
        return this->ifBinarySearchTree(postorder, low, index - 1) && this->ifBinarySearchTree(postorder, index, high - 1);
    }

public:
    bool verifyPostorder(vector<int>& postorder) {
        return this->ifBinarySearchTree(postorder, 0, postorder.size() - 1);
    }
};