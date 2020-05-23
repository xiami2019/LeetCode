class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        rows = len(matrix)
        cols = len(matrix[0])
        rightCol = cols - 1
        topRow = 0

        while topRow < rows and rightCol >= 0:
            if matrix[topRow][rightCol] == target:
                return True
            
            if matrix[topRow][rightCol] > target:
                rightCol -= 1
                continue
            
            if matrix[topRow][rightCol] < target:
                topRow += 1
                continue
        return False