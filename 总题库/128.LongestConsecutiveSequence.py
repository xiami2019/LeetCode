class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set()
        maxLen = 0
        for num in nums:
            seen.add(num)
        
        for num in seen:
            if num - 1 in seen:
                continue

            tempLen = 0
            while num in seen:
                tempLen += 1
                num += 1
            maxLen = max(maxLen, tempLen)
        return maxLen