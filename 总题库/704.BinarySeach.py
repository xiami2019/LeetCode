class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        low, high = 0, len(nums) - 1

        while low < high:
            mid = (high - low + 1) // 2 + low
            if nums[mid] <= target:
                low = mid
            else:
                high = mid - 1
        return low if nums[low] == target else -1