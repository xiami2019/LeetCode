class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ''
        
        minLength = len(strs[0])
        for s in strs:
            minLength = min(minLength, len(s))
        low, high = 0, minLength
        while low < high:
            mid = (high - low + 1) // 2 + low
            if self.isCommonPrefix(strs, mid):
                low = mid
            else:
                high = mid - 1
        return strs[0][:low]

    def isCommonPrefix(self, strs: List[str], length: int) -> bool:
        str0 = strs[0][:length]
        counts = len(strs)
        for i in range(1, counts):
            for j in range(length):
                if str0[j] != strs[i][j]:
                    return False
        return True