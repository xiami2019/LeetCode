class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> walls;
        int totalRain = 0;
        int tempRain = 0;
        walls.push(0);
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] >= height[walls.top()]) {
                totalRain += tempRain;
                tempRain = 0;
                walls.push(i);
            }
            else {
                tempRain += height[walls.top()] - height[i];
            }
        }
        while (!walls.empty()) walls.pop();
        tempRain = 0;
        walls.push(height.size() - 1);
        for (int i = height.size() - 2; i >= 0; --i) {
            if (height[i] > height[walls.top()]) {
                totalRain += tempRain;
                tempRain = 0;
                walls.pop();
                walls.push(i);
            }
            else {
                tempRain += height[walls.top()] - height[i];
            }
        }
        return totalRain;
    }
};

// 遍历依此的栈解法：
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> walls;
        while (current < height.size()) {
            while (!walls.empty() && height[current] > height[walls.top()]) {
                int top = walls.top();
                walls.pop();
                if (walls.empty()) break;
                int distance = current - walls.top() - 1;
                int boundHeight = min(height[current], height[walls.top()]) - height[top];
                ans += boundHeight * distance;
            }
            walls.push(current++);
        }
        return ans;
    }
};

// 双指针法：
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                // 此时储水量由左leftMax决定；
                height[left] > leftMax ? leftMax = height[left] : ans += leftMax - height[left];
                ++left;
            }
            else {
                // 此时储水量由右rightMax决定；
                height[right] > rightMax ? rightMax = height[right] : ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};