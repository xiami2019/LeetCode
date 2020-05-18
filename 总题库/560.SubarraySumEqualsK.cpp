// Christiano Ronaldo
// 暴力
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int numsLen = nums.size();
        for (int i = 0; i < numsLen; i++) {
            int subSum = 0;
            for (int j = i; j < numsLen; j++) {
                subSum += nums[j];
                if (subSum == k) res++;
            }
        }
        return res;
    }
};

// 前缀和
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (int i : nums) {
            pre += i;
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};