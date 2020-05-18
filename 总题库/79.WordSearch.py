class Solution:
    def __init__(self):
        super().__init__()
        self.addX = [1, -1, 0, 0]
        self.addY = [0, 0, 1, -1]
    
    def dfs(self, board: List[List[str]], word: str, index: int, x: int, y: int) -> bool:
        if index == len(word):
            return True;

        rows = len(board)
        cols = len(board[0])

        for i in range(4):
            newX = x + self.addX[i]
            newY = y + self.addY[i]
            if newX >= 0 and newX < rows and newY >= 0 and newY < cols:
                if board[newX][newY] == word[index]:
                    temp = board[newX][newY]
                    board[newX][newY] = ' '
                    if (self.dfs(board, word, index + 1, newX, newY)):
                        return True
                    board[newX][newY] = temp
        return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        rows = len(board)
        cols = len(board[0])
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0]:
                    temp = board[i][j]
                    board[i][j] = ' '
                    if (self.dfs(board, word, 1, i, j)):
                        return True
                    board[i][j] = temp
        return False