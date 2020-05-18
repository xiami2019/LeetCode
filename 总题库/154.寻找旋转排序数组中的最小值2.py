class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low < high:
            middle = (low + high) >> 1
            if nums[middle] < nums[high]:
                high = middle
            elif nums[middle] > nums[high]:
                low = middle + 1
            else:
                high -= 1
        return nums[low]