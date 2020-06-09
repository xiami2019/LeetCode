class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int maxLength = 0;
        for (int i : nums) {
            seen.insert(i);
        }
        for (auto iter = seen.begin(); iter != seen.end(); iter++) {
            if (seen.count(*iter - 1)) continue;
            int num = *iter;
            int tempLength = 0;
            while (seen.count(num)) {
                ++tempLength;
                ++num;
            }
            maxLength = max(maxLength, tempLength);
        }
        return maxLength;
    }
};