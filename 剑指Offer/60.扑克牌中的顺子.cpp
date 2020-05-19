class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int Zeros = 0;
        int index = 0;
        while (nums[index] == 0) {
            Zeros++;
            index++;
        }
        if (Zeros == 4) return true;

        int sequence = nums[index++];
        while (index < 5) {
            if (nums[index] == nums[index - 1]) return false;
            sequence++;
            if (nums[index] != sequence) {
                if (Zeros > 0) {
                    Zeros--;
                }
                else {
                    return false;
                }
            }
            else {
                index++;
            }
        }
        return true;
    }
};


// 解法2
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_set<int> seen;
        int maxNum = 0, minNum = 14;
        for (int i : nums) {
            if (i == 0) continue;
            maxNum = max(maxNum, i);
            minNum = min(minNum, i);
            if (seen.count(i)) return false;
            seen.insert(i);
        }
        return maxNum - minNum < 5;
    }
};