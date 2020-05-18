class Solution {
// 使用set容器
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> numbers;
        for (int i: nums){
            if (numbers.find(i) != numbers.end()){
                return i;
            }
            else {
                numbers.insert(i);
            }
        }
        return 0;
    }
};

/*
法二：原地置换
如果没有重复数字，那么正常排序后，数字i应该在下标为i的位置，所以思路是重头扫描数组，遇到下标为i的数字如果不是i的话，
假设为m，那么我们就拿它与下标m的数字交换。在交换过程中，如果有重复的数字发生，那么终止返回true。
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp, numsLen = nums.size();
        for (int i = 0; i < numsLen; i++){
            while (nums[i] != i){
                if (nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};