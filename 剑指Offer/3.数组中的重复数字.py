# 使用辅助数组的方法
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        seen = set()
        for num in nums:
            if num in seen:
                return num
            else:
                seen.add(num)
        return -1 # 代表没有找到重复的数字

# 不使用辅助数组
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums):
            if nums[i] != i:
                if nums[i] == nums[nums[i]]:
                    return nums[i]
                else:
                    temp = nums[i]
                    nums[i] = nums[nums[i]]
                    nums[temp] = temp
            else:
                i += 1

        return -1


