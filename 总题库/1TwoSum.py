class Solution:
    def twoSum(self, nums: List[int], target: int) ->List[int]:
        seen = {};
        
        for index, item in enumerate(nums):
            if target - item in seen:
                return [seen[target - item], index]
            else:
                seen[item] = index
                
        return []