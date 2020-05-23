class Solution:
    def __init__(self):
        self.addX = [1, -1, 0, 0]
        self.addY = [0, 0, 1, -1]
        self.cellsCounts = 0
    
    def getDigitSum(self, x: int, y: int) -> int:
        res = 0
        while x != 0 or y != 0:
            if x:
                res += x % 10
                x //= 10
            if y:
                res += y % 10
                y //= 10
        return res
            
    def backtrack(self, visited: List[List[int]], m: int, n: int, k: int, x: int, y: int) -> None:
        for i in range(4):
            newX = x + self.addX[i]
            newY = y + self.addY[i]
            if newX >= 0 and newX < m and newY >= 0 and newY < n and visited[newX][newY] == 0:
                if self.getDigitSum(newX, newY) <= k:
                    self.cellsCounts += 1
                    visited[newX][newY] = 1
                    self.backtrack(visited, m, n, k, newX, newY);

    def movingCount(self, m: int, n: int, k: int) -> int:
        visited = [[0 for i in range(n)] for j in range(m)]
        visited[0][0] = 1
        self.cellsCounts += 1
        self.backtrack(visited, m, n, k, 0, 0)
        return self.cellsCounts