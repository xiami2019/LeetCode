class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = set() # 记录一个字符是否出现过
        n = len(s)
        rk, ans = -1, 0
        for i in range(n):
            if i != 0:
                # 左指针向右移动一位，删除一个字符
                seen.remove(s[i - 1])
            while rk + 1 < n and s[rk + 1] not in seen:
                # 不断地移动右指针
                seen.add(s[rk + 1])
                rk += 1

            # 第i到rk个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1)
        return ans;