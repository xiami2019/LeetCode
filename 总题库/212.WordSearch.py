class Trie:
    def __init__(self):
        super().__init__()
        self.word = ""
        self.nodes = {}

    def insert(self, word: str) -> None:
        root = self
        for c in word:
            if c not in root.nodes:
                root.nodes[c] = Trie()
            root = root.nodes[c]
        root.word = word

    def search(self, word: str) -> bool:
        root = self
        for c in word:
            if c not in root.nodes:
                return False
            root = root.nodes[c]
        return root.word == word


class Solution:
    def __init__(self):
        super().__init__()
        self.res = []
        self.rows = 0
        self.cols = 0

    def dfs(self, board: List[List[str]], trieTree: Trie, x: int, y: int) -> None:
        tempChar = board[x][y]
        if tempChar == '.' or tempChar not in trieTree.nodes :
            return None
        trieTree = trieTree.nodes[tempChar]
        if trieTree.word != "":
            self.res.append(trieTree.word)
            trieTree.word = ""

        board[x][y] = '.'
        if x > 0:
            self.dfs(board, trieTree, x - 1, y)
        if y > 0:
            self.dfs(board, trieTree, x, y - 1)
        if x + 1 < self.rows:
            self.dfs(board, trieTree, x + 1, y)
        if y + 1 < self.cols:
            self.dfs(board, trieTree, x, y + 1)
        board[x][y] = tempChar

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trieTree = Trie()
        self.rows = len(board)
        self.cols = 0 if self.rows == 0 else len(board[0])

        for word in words:
            trieTree.insert(word)

        for i in range(self.rows):
            for j in range(self.cols):
                self.dfs(board, trieTree, i, j)
        
        return self.res
