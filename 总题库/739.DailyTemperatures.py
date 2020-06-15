class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        s = []
        res = [0 for _ in range(len(T))]
        for i in range(len(T)):
            while len(s) != 0 and T[i] > T[s[-1]]:
                res[s[-1]] = i - s[-1]
                s.pop()
            s.append(i)
        return res