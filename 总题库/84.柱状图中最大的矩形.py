# 栈里的元素都作为哨兵
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        s = [-1]
        for index, item in enumerate(heights):
            while s[len(s) - 1] != -1 and heights[s[len(s) - 1]] >= item:
                maxArea = max(maxArea, heights[s.pop()] * (index - 1 - s[len(s) - 1]))
            s.append(index)

        while s[len(s) - 1] != -1:
            maxArea = max(maxArea, heights[s.pop()] * (len(heights) - 1 - s[len(s) - 1]))

        return maxArea
