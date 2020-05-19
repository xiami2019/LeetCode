class Solution:
    def checkPalindrome(self, s: str, low: int, high: int) -> bool:
        i = low
        j = high
        while i <= j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        
        return True

    def validPalindrome(self, s: str) -> bool:
        low = 0
        high = len(s) - 1

        while low <= high:
            if s[low] == s[high]:
                low += 1
                high -= 1
            else:
                return self.checkPalindrome(s, low + 1, high) or self.checkPalindrome(s, low, high - 1)
        
        return True