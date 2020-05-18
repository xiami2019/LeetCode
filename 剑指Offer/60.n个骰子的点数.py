class Solution:
    def twoSum(self, n: int) -> List[float]:
        if n < 1:
            return []
        
        pProbabilities = [[0] * (6 * n + 1) for i in range(2)]

        flag = 0

        for i in range(1,7):
            pProbabilities[flag][i] = 1
        
        for k in range(2, n + 1):
            for i in range(k):
                pProbabilities[1 - flag][i] = 0

            for i in range(k, 6 * k + 1):
                pProbabilities[1 - flag][i] = 0
                for j in range(1, 7):
                    if j <= i:
                        pProbabilities[1 - flag][i] += pProbabilities[flag][i - j]
            flag = 1 - flag

        total = 6 ** n;
        ans = []
        for i in range(n, 6 * n + 1):
            ans.append(pProbabilities[flag][i] / total)

        return ans