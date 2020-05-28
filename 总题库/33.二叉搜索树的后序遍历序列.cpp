class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }

    bool verifyPostorder(vector<int>& postorder, int left, int right) {
        if (right - left < 0) return true;
        int root = postorder.back();
        int index = left;
        while (index < right && postorder[index] < root) index++;
        for (int i = index; i < right; i++) {
            if (postorder[i] < root) return false;
        }
        return verifyPostorder(postorder, left, index - 1) && verifyPostorder(postorder, index, right - 1);
    }
};