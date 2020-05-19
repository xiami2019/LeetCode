class Solution:
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        if n < 2:
            return True
        
        s = s.lower()
        low = 0
        high = n - 1
        while low < high:
            if (s[low] < 'a' or s[low] > 'z') and (s[low] > '9' or s[low] < '0'):
                low += 1
                continue
            if (s[high] < 'a' or s[high] > 'z') and (s[high] > '9' or s[high] < '0'):
                high -= 1
                continue
            if s[low] != s[high]:
                print(s[low], s[high])
                return False
            low += 1
            high -= 1
        return True