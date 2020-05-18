class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        numsLen = len(nums)
        if numsLen < k:
            return []

        maxNumberInWindows = []
        maxNumbers = []
        index = 0;

        while index < numsLen:
            if index >= k:
                if nums[index - k] == maxNumbers[0]:
                    maxNumbers.pop(0)

            while len(maxNumbers) != 0 and nums[index] > maxNumbers[len(maxNumbers) - 1]:
                maxNumbers.pop()
            maxNumbers.append(nums[index])

            if index >= k - 1:
                maxNumberInWindows.append(maxNumbers[0])

            index += 1
        
        return maxNumberInWindows
