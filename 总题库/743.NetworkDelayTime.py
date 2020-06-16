# DFS
class Solution:
    def networkDelayTime(self, times, N, K):
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((w, v))
        
        # dist[node]记录的是信号最早到达node的时间。当我们访问node时，若当前信号
        # 是最早到达该节点的，则我们广播这个信号；
        # 为了加快节点速度，在访问每个节点时，若传递该信号的时间比已有信号到达的时间
        # 长，则我们退出该信号，进行剪枝。
        dist = {node: float('inf') for node in range(1, N + 1)}

        def dfs(node, elapsed):
            # elapsed记录的是一个时间戳，代表当前的时间
            if elapsed >= dist[node]:
                return
            dist[node] = elapsed
            for time, nei in sorted(graph[node]):
                dfs(nei, elapsed + time)
        
        dfs(K, 0)
        ans = max(dist.values())
        return ans if ans < float('inf') else -1

# Dijkstra算法
class Solution:
    def networkDelayTime(self, times, N, K):
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))
        dist = {node: float('inf') for node in range(1, N + 1)}
        seen = [False] * (N + 1)
        dist[K] = 0

        while True:
            cand_node = -1
            cand_dist = float('inf')
            for i in range(1, N + 1):
                if not seen[i] and dist[i] < cand_dist:
                    cand_dist = dist[i]
                    cand_node = i

            if cand_node < 0:
                # 说明已经遍历完所有的节点了
                break;

            seen[cand_node] = True
            for nei, d in graph[cand_node]:
                dist[nei] = min(dist[nei], dist[cand_node] + d)

        ans = max(dist.values())
        return ans if ans < float('inf') else -1

# 堆实现：
class Solution:
    def networkDelayTime(self, times, N, K):
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))
        
        pq = [(0, K)]
        dist = {}
        while pq:
            d, node = heapq.heappop(pq)
            if node in dist:
                continue
            dist[node] = d
            for nei, d2 in graph[node]:
                if nei not in dist:
                    heapq.heappush(pq, (d + d2, nei))
        return max(dist.values()) if len(dist) == N else -1