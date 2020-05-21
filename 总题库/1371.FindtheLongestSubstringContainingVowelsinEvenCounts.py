class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        ans = 0
        status = 0
        n = len(s)
        pos = [-1] * (1 << 5) # 记录一个奇偶状态最早出现的位置
        pos[0] = 0

        for i in range(n):
            if s[i] == 'a':
                status ^= 1 << 0
            elif s[i] == 'e':
                status ^= 1 << 1
            elif s[i] == 'i':
                status ^= 1 << 2
            elif s[i] == 'o':
                status ^= 1 << 3
            elif s[i] == 'u':
                status ^= 1 << 4

            if ~pos[status]:
                ans = max(ans, i + 1 - pos[status])
            else:
                pos[status] = i + 1

        return ans