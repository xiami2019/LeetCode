class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            if nums[right] >= nums[left]: 
                return nums[left]
            middle = (left + right) >> 1
            if middle > 0 and nums[middle] < nums[middle - 1]:
                return nums[middle]
            elif nums[middle] < nums[right]:
                right = middle - 1
            else:
                left = middle + 1
        return 0