class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s) == 0 or s[0] == '0':
            return 0
        pre = 1
        cur = 1
        for i in range(1, len(s)):
            tmp = cur
            if s[i] == '0':
                if s[i - 1] == '1' or s[i - 1] == '2':
                    cur = pre
                else:
                    return 0
            elif s[i - 1] == '1' or (s[i - 1] == '2' and s[i] >= '1' and s[i] <= '6'):
                cur = cur + pre
            pre = tmp
        return cur