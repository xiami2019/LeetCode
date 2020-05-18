class Solution {
public:
//法1：暴力；
    vector<int> exchange(vector<int>& nums) {
        stack<int> even, odd;
        vector<int> result;

        for (int i : nums){
            if (i & 1 == 1){
                odd.push(i);
            }
            else{
                even.push(i);
            }
        }

        while (!odd.empty()){
            result.push_back(odd.top());
            odd.pop();
        }

        while (!even.empty()){
            result.push_back(even.top());
            even.pop();
        }

        return result;
    }
};

//法2：双指针；
//首尾双指针，交换奇数和偶数的位置；
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right){
            while (left < right && (nums[left] & 1) == 1){ //使用按位与和按位或使要注意运算符顺序
                left++;
            }
            while (left < right && (nums[right] & 1) == 0){
                right--;
            }
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }

        return nums;
    }
};

//快慢指针
//快指针指奇数，慢指针指偶数
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size()){
            if (nums[fast] & 1){
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow++;
            }
            fast++;
        }

        return nums;
    }
};