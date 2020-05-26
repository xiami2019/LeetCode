class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (1) {
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
            if (slow == fast) break;
        }
        slow = 0;

        while (nums[slow] != nums[fast]) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return nums[slow];
    }
};