class UnionFind:

    def __init__(self):
        self.parents = [i for i in range(26)]
        self.rank = [0 for _ in range(26)]

    def find(self, index: int) -> int:
        if index == self.parents[index]:
            return index

        self.parents[index] = self.find(self.parents[index])
        return self.parents[index]

    def unite(self, index1: int, index2: int) -> int:
        root1 = self.find(index1)
        root2 = self.find(index2)

        if root1 != root2:
            if self.rank[root1] < self.rank[root2]:
                self.parents[root1] = root2
            elif self.rank[root1] > self.rank[root2]:
                self.parents[root2] = root1
            else:
                self.parents[root2] = root1
                self.rank[root1] += 1


class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = UnionFind()
        for s in equations:
            if s[1] == '=':
                index1 = ord(s[0]) - ord('a')
                index2 = ord(s[3]) - ord('a')
                uf.unite(index1, index2)

        for s in equations:
            if s[1] == '!':
                index1 = ord(s[0]) - ord('a')
                index2 = ord(s[3]) - ord('a')
                if uf.find(index1) == uf.find(index2):
                    return False

        return True