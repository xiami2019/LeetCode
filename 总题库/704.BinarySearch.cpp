class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low; // 这种写法可以防止溢出
            if (nums[mid] <= target) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return nums[low] == target ? low : -1;
    }
};
