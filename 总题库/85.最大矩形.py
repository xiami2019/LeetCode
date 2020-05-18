# Python是强类型的动态语言

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

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0

        rows = len(matrix)
        cols = len(matrix[0])
        mat = [[0 * cols] for i in range(rows)]
        maxRectangle = 0
        for i in range(rows):
            for j in range(cols):
                if i == 0:
                    mat[i][j] = int(matrix[i][j])
                else:
                    mat[i][j] = 0 if matrix[i][j] == '0' else mat[i - 1][j] + 1
                
        for i in range(rows):
            s = [-1]
            for index, item in enumerate(mat[i]):
                while s[len(s) - 1] != -1 and mat[i][s[len(s) - 1]] >= item:
                    maxRectangle = max(maxRectangle, mat[i][s.pop()] * (index - 1 - s[len(s) - 1]))
                s.append(index)
            
            while s[len(s) - 1] != -1:
                maxRectangle = max(maxRectangle, mat[i][s.pop()] * (cols - 1 - s[len(s) - 1]))

        return maxRectangle

                
