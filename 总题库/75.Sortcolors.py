class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) < 2:
            return None
        
        low = 0
        high = len(nums) - 1
        index = 0
        while index <= high:
            if nums[index] == 0:
                nums[index], nums[low] = nums[low], nums[index]
                index += 1
                low += 1
            elif nums[index] == 2:
                nums[index], nums[high] = nums[high], nums[index]
                high -= 1
            else:
                index += 1
