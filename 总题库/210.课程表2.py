class Solution:
    def __init__(self):
        super().__init__()
        self.edges = []
        self.indeg = []
        self.result = []

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        self.edges = [[] for i in range(numCourses)]
        self.indeg = [0 for i in range(numCourses)]

        for pair in prerequisites:
            self.edges[pair[1]].append(pair[0])
            self.indeg[pair[0]] += 1

        q = []
        for i in range(numCourses):
            if self.indeg[i] == 0:
                q.append(i)

        while len(q) != 0:
            u = q[0]
            q.pop(0)
            self.result.append(u)

            for item in self.edges[u]:
                self.indeg[item] -= 1
                if self.indeg[item] == 0:
                    q.append(item)
        
        if len(self.result) != numCourses:
            return []
        else:
            return self.result