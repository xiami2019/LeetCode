class Solution:
    def permutation(self, s: str) -> List[str]:
        c, res = list(s), []

        def dfs(x):
            if x == len(c) - 1:
                # 已经完成了一组排列
                res.append(''.join(c))
                return
            
            seen = set() # 用于去重
            for i in range(x, len(c)):
                if c[i] in seen:
                    continue
                seen.add(c[i])
                c[x], c[i] = c[i], c[x]
                dfs(x + 1)
                c[x], c[i] = c[i], c[x]
        
        dfs(0)
        return res