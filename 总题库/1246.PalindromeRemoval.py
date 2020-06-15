class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        arrLen = len(arr)
        if arrLen == 0:
            return 0
        dp = [[0 for _ in range(arrLen)] for _ in range(arrLen)]

        for i in range(arrLen):
            dp[i][i] = 1
        
        for i in range(arrLen - 1):
            if arr[i] == arr[i + 1]:
                dp[i][i + 1] = 1
            else:
                dp[i][i + 1] = 2
        
        for intervalLen in range(2, arrLen):
            for i in range(0, arrLen - intervalLen):
                dp[i][i + intervalLen] = intervalLen + 1
                for k in range(0, intervalLen):
                    if dp[i][i + intervalLen] > dp[i][i + k] + dp[i + k + 1][i + intervalLen]:
                        dp[i][i + intervalLen] = dp[i][i + k] + dp[i + k + 1][i + intervalLen]
                
                if arr[i] == arr[i + intervalLen] and dp[i][i + intervalLen] > dp[i + 1][i + intervalLen - 1]:
                    dp[i][i + intervalLen] = dp[i + 1][i + intervalLen - 1]
        
        return dp[0][arrLen - 1]