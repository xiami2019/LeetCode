class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        if len(nums) < 2:
            return nums;
        
        left = 0
        right = len(nums) - 1

        while left < right:
            while left < right and nums[left] & 1:
                left += 1
            while left < right and (nums[right] & 1) == 0:
                right -= 1
            temp = nums[left]
            nums[left] = nums[right]
            nums[right] = temp

        return nums
