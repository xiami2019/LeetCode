class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        result = []
        for index,item in enumerate(nums):
            if target - item in hashmap:
                result.append(hashmap[target - item])
                result.append(index)
                break;
            else:
                hashmap[item] = index
        return result