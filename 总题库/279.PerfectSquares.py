# 暴力枚举
# 超时，递归堆栈溢出问题
class Solution:
    def numSquares(self, n: int) -> int:
        squareNums = [i ** 2 for i in range(math.sqrt(n) + 1)]
        def minNumSquares(k):
            '''
            recursive solution
            '''
            # bottom cases: find a square number
            if k in squareNums:
                return 1
            minNum = float('-inf')

            # Find the minimal value among all possible solutions
            for square in squareNums:
                if k < square:
                    break
                newNum = minNumSquares(k - square) + 1
                minNum = min(minNum, newNum)
            return minNum
        return minNumSquares(n)

# 动态规划，使用一个动态规划记忆数组来保存中间解的值
class Solution:
    def numSquares(self, n: int) -> int:
        squareNums = [i ** 2 for i in range(int(math.sqrt(n) + 1))]
        dp = [float('inf')] * (n + 1) # dp数组的元素dp[i]代表组成数值i的最小完全平方数的个数，使用DP数组可以使得中间的解只计算一次
        dp[0] = 0 # 组成0需要0个完全平方数
        for i in range(1, n + 1):
            for square in squareNums:
                if i < square: # 如果平方数已经超越了此时的总数，则已经不可能，需要break；
                    break
                dp[i] = min(dp[i], dp[i - square] + 1) # 计算出组成数值i的最少的完全平方数的个数；
        return dp[n] # 通常来说DP数组的最后一个数就是最终解；

# 贪心枚举（从小到达枚举组成数的个数）
class Solution:
    def numSquares(self, n: int) -> int:
        squareNums = [i ** 2 for i in range(int(math.sqrt(n) + 1))]
        def isDividedBy(n, count) -> bool:
            '''
            return true if n can be decomposed into "counts" number of perfect square numbers.
            '''
            if count == 1:
                # 当n只能由一个完全平方数组成时，只需要检查n是不是完全平方数即可；
                return n in squareNums
            
            for square in squareNums:
                # 遍历平方数列表中的每一个平方数
                if n < square: # 剪枝，确保n - square为一个正数
                    break
                if isDividedBy(n - square, count - 1): # 组成目标数的数的个数减一，目标数减去square；
                    return True
            return False

        for i in range(1, n + 1):
            if isDividedBy(n, i): # 因为count是从小到大枚举的，所以第一个为True时返回的就是最小的组成个数
                return i
    
# 贪心加BFS
'''
贪心枚举实际构造的是一棵N叉树，每个节点都代表isDividedBy(n, count)的一次函数调用；
给定一个 N 元树，其中每个节点表示数字 n 的余数减去一个完全平方数的组合，我们的任务是在树中找到一个节点，该节点满足两个条件：
(1) 节点的值（即余数）也是一个完全平方数。
(2) 在满足条件（1）的所有节点中，节点和根之间的距离应该最小。
前面的方法3中，由于我们执行调用的贪心策略，我们实际上是从上到下逐层构造 N 元树。我们以 BFS（广度优先搜索）的方式遍历它。在 N 元树的每一级，我们都在枚举相同大小的组合；
遍历的顺序是 BFS，而不是 DFS（深度优先搜索），这是因为在用尽固定数量的完全平方数分解数字 n 的所有可能性之前，我们不会探索任何需要更多元素的潜在组合；
实际上就是对这个N叉树进行层序遍历，最先满足条件的层就是组成目标数的数字的最小个数。
'''
class Solution:
    def numSquares(self, n: int) -> int:
        # list of square numbers that are less than n
        numSquares = [i ** 2 for i in range(1, int(math.sqrt(n) + 1))]
        level = 0
        queue = {n}

        while queue:
            level += 1
            nextQueue = set()
            for remainder in queue:
                for square in squareNums:
                    if square == remainder:
                        # 找到了个组成目标数的完全平方数的组合
                        return level
                    if remainder < square:
                        # 剪枝
                        break
                    nextQueue.add(remainder - square)
            queue = nextQueue
        return level

# 数学法
class Solution:
    def numSquares(self, n: int) -> int:
