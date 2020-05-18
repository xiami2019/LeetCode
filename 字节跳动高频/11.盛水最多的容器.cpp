/*
简化版的接雨水
双指针法
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int heightLen = height.size();
        int left = 0, right = heightLen - 1;
        int maxWater = INT_MIN;
        // 存水量由低的一侧决定，所以将低的那边的指针向高的那边移动。
        while (left < right) {
            if (height[left] <= height[right]){
                maxWater = max(maxWater, height[left] * (right - left));
                left++;
            }
            else {
                maxWater = max(maxWater, height[right] * (right - left));
                right--;
            }
        }
        return maxWater;
    }
};