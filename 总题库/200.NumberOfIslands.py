class Solution:
    def __init__(self):
        self.addX = [1, -1, 0, 0]
        self.addY = [0, 0, 1, -1]
    
    def dfs(self, grid: List[List[str]], x: int, y: int, rows: int, cols: int):
        for i in range(4):
            newX = x + self.addX[i]
            newY = y + self.addY[i]
            if newX >= 0 and newX < rows and newY >= 0 and newY < cols and grid[newX][newY] == '1':
                grid[newX][newY] = '0';
                self.dfs(grid, newX, newY, rows, cols)

    def bfs(self, grid: List[List[str]], x: int, y: int, rows: int, cols: int):
        q = [[x, y]]
        while len(q):
            x, y = q[0]
            q.pop(0)
            for i in range(4):
                newX = x + self.addX[i]
                newY = y + self.addY[i]
                if newX >= 0 and newX < rows and newY >= 0 and newY < cols and grid[newX][newY] == '1':
                    grid[newX][newY] = '0';
                    q.append([newX, newY])


    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0;
        
        islandsNumber = 0;
        rows = len(grid)
        cols = len(grid[0])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    islandsNumber += 1
                    grid[i][j] = '0'
                    # self.dfs(grid, i, j, rows, cols)
                    self.bfs(grid, i, j, rows, cols)
        
        return islandsNumber