class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        mx = A[0] + 0
        res = float('-inf')
        for i in range(1, len(A)):
            res = max(res, mx + A[i] - i)
            mx = max(mx, A[i] + i)
        
        return res