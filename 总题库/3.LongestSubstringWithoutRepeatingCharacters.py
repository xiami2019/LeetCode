# 使用字典实现
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        indexes = {}
        if len(s) <= 1:
            return len(s)

        maxLen = -1
        low = 0
        high = 1
        tempLen = 1
        indexes[s[0]] = 0
        while high < len(s):
            if s[high] not in indexes or indexes[s[high]] < low:
                indexes[s[high]] = high
                tempLen += 1
                high += 1
            else:
                maxLen = max(maxLen, tempLen)
                tempLen = tempLen - (indexes[s[high]] - low + 1) + 1
                low = indexes[s[high]] + 1
                indexes[s[high]] = high
                high += 1
        maxLen = max(maxLen, tempLen)

        return maxLen
        

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 哈希集合，记录每个字符是否出现过
        occ = set()
        n = len(s)
        # 右指针，初始值为-1，相当于我们在字符串的左边界的左侧，还没有开始移动
        rk, ans = -1, 0
        for i in range(n):
            if i != 0:
                # 左指针向右移动一格，移除一个字符
                occ.remove(s[i - 1])
            while rk + 1 < n and s[rk + 1] not in occ:
                occ.add(s[rk + 1])
                rk += 1
            ans = max(ans, rk - i + 1)
        return ans
