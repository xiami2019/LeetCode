class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 0:
            return False
        border = nums[0]
        index = 0
        while index < len(nums) and index <= border:
            border = max(border, index + nums[index])
            if border >= len(nums) - 1:
                return True
            index += 1
            
        return False