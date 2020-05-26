class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []

        topRow = 0
        bottomRow = len(matrix) - 1
        leftCol = 0
        rightCol = len(matrix[0]) - 1

        counts = (bottomRow + 1) * (rightCol + 1)
        res = []

        while counts > 0:
            for i in range(leftCol, rightCol + 1):
                res.append(matrix[topRow][i])
                counts -= 1
            topRow += 1
            if counts <= 0: break

            for i in range(topRow, bottomRow + 1):
                res.append(matrix[i][rightCol])
                counts -= 1
            rightCol -= 1
            if counts <= 0: break

            for i in range(rightCol, leftCol - 1, -1):
                res.append(matrix[bottomRow][i])
                counts -= 1
            bottomRow -= 1
            if counts <= 0: break

            for i in range(bottomRow, topRow - 1, -1):
                res.append(matrix[i][leftCol])
                counts -= 1
            leftCol += 1
        return res