/*
方法一：
先排序，再线性遍历。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minPositive = 1;
        for (int i : nums) {
            if (i > 0) {
                if (i < minPositive) {
                    continue;
                }
                if (i == minPositive) {
                    minPositive++;
                }
                else return minPositive;
            }
        }
        return minPositive;
    }
};

/*
方法二：
索引作为哈希表
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        bool contains = false; // 判断是否包含1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                contains = true;
                break;
            }
        }

        if (!contains) return 1;
        if (n == 1) return 2; // 只包含一个元素且为1，则缺失的最小正数是2

        // 用1替换所有非正数和大于n的数
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        // 使用索引和数字符号作为检查器
        // 如果nusm[1]是负数表示在数组中出现了数字“1”
        // 如果nums[2]是正数，表示数字2没有出现
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);
            // 如果发现了一个数字a，改变第a个元素的符号
            // 注意重复元素只需操作一次
            if (a == n) nums[0] = -1 * abs(nums[0]);
            else nums[a] = -1 * abs(nums[a]);
        }
    
        // 现在第一个正数的下标就是缺失的最小正数
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }

        if (nums[0] > 0) return n;

        return n + 1;
    }    
};