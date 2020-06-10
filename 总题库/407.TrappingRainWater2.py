import heapq # Python3中的堆操作；

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not len(heightMap) or not len(heightMap[0]):
            return 0

        rows, cols = len(heightMap), len(heightMap[0]);
        pq = [] # pq is a priority queue, implemented with heap.
        visited = [[False for _ in range(cols)] for _ in range(rows)]
        dirs = [-1, 0, 1, 0, -1]
        ans = 0

        # 首先存入最外圈的边界
        for i in range(rows):
            heapq.heappush(pq, (heightMap[i][0], i, 0))
            heapq.heappush(pq, (heightMap[i][cols - 1], i, cols - 1))
            visited[i][0] = True
            visited[i][cols - 1] = True

        for i in range(cols):
            heapq.heappush(pq, (heightMap[0][i], 0, i))
            heapq.heappush(pq, (heightMap[rows - 1][i], rows - 1, i))
            visited[0][i] = True
            visited[rows - 1][i] = True

        while pq:
            cur = heapq.heappop(pq)

            for i in range(4):
                newX, newY = cur[1] + dirs[i], cur[2] + dirs[i + 1]
                if newX >= 0 and newX < rows and newY >= 0 and newY < cols and visited[newX][newY] == False:
                    if cur[0] > heightMap[newX][newY]:
                        ans += cur[0] - heightMap[newX][newY]
                        heightMap[newX][newY] = cur[0]
                    heapq.heappush(pq, (heightMap[newX][newY], newX, newY))
                    visited[newX][newY] = True

        return ans