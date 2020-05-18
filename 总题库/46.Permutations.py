# 回溯法
class Solution:
    def __init__(self):
        super().__init__()
        self.res = []

    def backtrack(self, nums: List[int], index: int) -> None:
        if index == len(nums) - 1:
            self.res.append(nums[::])

        for i in range(index, len(nums)):
            nums[index], nums[i] = nums[i], nums[index]
            self.backtrack(nums, index + 1)
            nums[index], nums[i] = nums[i], nums[index]

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.backtrack(nums, 0)
        return self.res