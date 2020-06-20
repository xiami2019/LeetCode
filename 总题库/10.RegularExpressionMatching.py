class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        sLen, pLen = len(s), len(p)
        dp = [[False for _ in range(pLen + 1)] for _ in range(sLen + 1)]
        dp[0][0] = True
        for i in range(sLen + 1):
            for j in range(1, pLen + 1):
                if p[j - 1] == '*':
                    dp[i][j] |= dp[i][j - 2]
                    if i > 0 and (p[j - 2] == '.' or p[j - 2] == s[i - 1]):
                        dp[i][j] |= dp[i - 1][j]
                else:
                    if i > 0 and (p[j - 1] == '.' or p[j - 1] == s[i - 1]):
                        dp[i][j] |= dp[i - 1][j - 1]
        return dp[sLen][pLen]