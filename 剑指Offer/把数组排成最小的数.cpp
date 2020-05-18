/*
法一：暴力找出所有全排列，然后比较大小，选出一个最小的；
*/

/*
法二：自定义排序规则
*/

class Solution {
    bool cmp(int a, int b) {
        string aStr = to_string(a);
        string bStr = to_string(b);
        if (aStr + bStr > bStr + aStr) return aStr > bStr;
        else {
            return aStr < bStr;
        }
    }

public:
    string minNumber(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen == 0) return "";

        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        return res;
    }
};