class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        seen = set()
        maxNum = 0
        minNum = 14
        for number in nums:
            if number == 0:
                continue
            maxNum = max(maxNum, number)
            minNum = min(minNum, number)
            if number in seen:
                return False
            seen.add(number)

        return maxNum - minNum < 5