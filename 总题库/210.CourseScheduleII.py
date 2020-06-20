class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjacency = [[] for _ in range(numCourses)]
        inDegrees = [0 for _ in range(numCourses)]
        res = []
        for item in prerequisites:
            inDegrees[item[0]] += 1
            adjacency[item[1]].append(item[0])
        q = []
        for index, i in enumerate(inDegrees):
            if i == 0:
                q.append(index)
        
        while len(q):
            curCourse = q[0]
            q.pop(0)
            res.append(curCourse)
            for index, i in enumerate(adjacency[curCourse]):
                inDegrees[i] -= 1
                if inDegrees[i] == 0:
                    q.append(i)

        if len(res) != numCourses:
            return []
        else:
            return res
