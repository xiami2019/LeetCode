class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        ret = 0
        for i in nums:
            ret ^= i
        div = 1
        while div & ret == 0:
            div <<= 1
        a = 0
        b = 0

        for i in nums:
            if div & i == 0:
                a ^= i
            else:
                b ^= i
        return [a, b]