class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        n = len(S)
        size = 0
        for c in S:
            if c.isdigit():
                size *= int(c)
            else:
                size += 1
        
        for i in range(n - 1, -1, -1):
            K %= size
            if K == 0 and S[i].isalpha():
                return S[i] 
            if S[i] >= '0' and S[i] <= '9':
                size /= int(S[i])
            else:
                size -= 1
        return ''
        