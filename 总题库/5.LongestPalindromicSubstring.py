# 中心扩展法
class Solution:
    def expandPalindrome(self, s: str, left: int, right: int) ->(int,int):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return (left + 1, right - 1)

    def longestPalindrome(self, s: str) -> str:
        start = 0
        end = 0
        for i in range(len(s)):
            left1, right1 = self.expandPalindrome(s, i, i)
            left2, right2 = self.expandPalindrome(s, i, i + 1)
            if right1 - left1 > end - start:
                end = right1
                start = left1
            if right2 - left2 > end - start:
                end = right2
                start = left2
        
        return s[start:end + 1]