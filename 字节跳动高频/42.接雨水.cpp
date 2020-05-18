class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        int rightWall = 0, leftWall = height.size() - 1;
        int hLen = height.size();
        int water = 0;
        for (int i = 1; i < hLen; i++){
            if (height[i] >= height[rightWall]){
                for (int j = rightWall; j < i; j++){
                    water += height[rightWall] - height[j];
                }
                rightWall = i;
            }
        }
        if (rightWall == leftWall) return water;

        for (int i = leftWall - 1; i >= 0; i--){
            if (height[i] > height[leftWall]){
                for (int j = leftWall; j > i; j--){
                    water += height[leftWall] - height[j];
                }
                leftWall = i;
            }
        }

        return water;
    }
};

/*
栈的应用
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int hLen = height.size(), ans = 0, current = 0;
        stack<int> st;
        while (current < hLen){
            while (!st.empty() && height[current] > height[st.top()]){
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = current - st.top() - 1;
                int boundedHeight = min(height[current], height[st.top()]) - height[top];
                ans += distance * boundedHeight;
            }
            st.push(current++);
        }
        return ans;
    }
};

/*
双指针法
如果一端有更高的条形快（例如右端），积水的高度依赖于当前方向的高度（从左到右）。
当我们发现另一侧（右侧）的条形块高度不是最高的，我们则开始从相反的方向遍历（从右到左）。
我们必须在遍历时维护left_max和right_max，但是我们现在可以使用两个指针交替进行，实现一次遍历即可完成。
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int leftMax = 0, rightMax = 0;
        while (left < right){
            if (height[left] < height[right]) {
                height[left] >= leftMax ? (leftMax = height[left]) : ans += (leftMax - height[left]);
                ++left;
            }
            else {
                height[right] >= rightMax ? (rightMax = height[right]) : ans += (rightMax - height[right]);
                --right;
            }
        }        
        return ans;
    }
};