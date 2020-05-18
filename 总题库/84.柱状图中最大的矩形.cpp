// 暴力
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int heightsLen = heights.size();
        if (heightsLen == 0) return 0;

        for (int i = 0; i < heightsLen; i++) {
            int minHeight = heights[i];
            for (int j = i; j < heightsLen; j++) {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, (j - i + 1) * minHeight);
            }
        }
        return maxArea;
    }
};

// 分治
class Solution {
    int calculateArea(vector<int>& heights, int start, int end) {
        if (start > end) return 0;
        int minindex = start;
        for (int i = start; i <= end; i++) {
            if (heights[minindex] > heights[i]) minindex = i;
        }
        return max(heights[minindex] * (end - start + 1), max(calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end)));
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        return this->calculateArea(heights, 0, heights.size() - 1);
    }
};

// 使用线段树优化的分治
// 时间复杂度：O(nlogn)。对于长度为n的查询，线段树需要logn的时间。
// 空间复杂度：O(n)。这是线段树的空间开销。
class SegTreeNode {
public:
    int start;
    int end;
    int min;
    SegTreeNode *left;
    SegTreeNode *right;
    SegTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        left = right = NULL;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        SegTreeNode *root = buildSegmentTree(heights, 0, heights.size() - 1);
        return calculateMax(heights, root, 0, heights.size() - 1);
    }

    SegTreeNode *buildSegmentTree(vector<int>& heights, int start, int end) {
        if (start > end) return NULL;
        SegTreeNode *root = new SegTreeNode(start, end);
        if (start == end) {
            root->min = start;
            return root;
        }
        else {
            int middle = (start + end) / 2;
            root->left = buildSegmentTree(heights, start, middle);
            root->right = buildSegmentTree(heights, middle + 1, end);
            root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
            return root;
        }
    }

    int query(SegTreeNode *root, vector<int>& heights, int start, int end) {
        // 利用线段树查询一个区间的最小值
        if (root == NULL || end < root->start || start > root->end) return -1;
        if (start <= root->start && end >= root->end) {
            return root->min;
        }
        int leftMin = query(root->left, heights, start, end);
        int rightMin = query(root->right, heights, start, end);
        if (leftMin == -1) return rightMin;
        if (rightMin == -1) return leftMin;
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
    }

    int calculateMax(vector<int>& heights, SegTreeNode* root, int start, int end) {
        if (start > end) {
            return -1;
        }
        if (start == end) {
            return heights[start];
        }
        int minIndex = query(root, heights, start, end);
        int leftMax = calculateMax(heights, root, start, minIndex - 1);
        int rightMax = calculateMax(heights, root, minIndex + 1, end);
        int minMax = heights[minIndex] * (end - start + 1);
        return max(max(leftMax, rightMax), minMax);
    }
};

// 栈方法
class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
        stack<int> s;
        s.push(-1);
        int heightsLen = heights.size();
        int maxarea = 0;
        for (int i = 0; i < heightsLen; i++) {
            while (s.top() != -1 && heights[s.top()] > heights[i]) {
                int temp = heights[s.top()];
                s.pop();
                maxarea = max(maxarea, temp * (i - s.top() - 1));
            }
            s.push(i);
        }
        while (s.top() != -1) {
            int temp = heights[s.top()];
            s.pop();
            maxarea = max(maxarea, temp * (heightsLen - 1 - s.top()));
        }
        return maxarea;
    }
};