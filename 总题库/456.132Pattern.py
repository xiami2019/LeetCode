class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        numsLen = len(nums)
        if numsLen < 3:
            return 0
        s = [] # 辅助栈
        
        minPrefix = [0 for _ in range(numsLen)]
        minPrefix[0] = nums[0]
        for i in range(1, numsLen):
            minPrefix[i] = min(minPrefix[i - 1], nums[i])

        for i in range(numsLen - 1, -1, -1):
            if nums[i] > minPrefix[i]:
                if len(s) == 0:
                    s.append(nums[i])
                else:
                    while len(s) != 0 and s[-1] < nums[i]:
                        if s[-1] > minPrefix[i]:
                            return True
                        s.pop()
                    s.append(nums[i])
        return False