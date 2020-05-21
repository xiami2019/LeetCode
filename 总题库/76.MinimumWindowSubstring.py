# 优化的滑动窗口

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # 特殊情况判断
        if len(s) == 0 or len(t) == 0:
            return ""
        
        dictT = {}
        for i in range(len(t)):
            if t[i] not in dictT:
                dictT[t[i]] = 1
            else:
                dictT[t[i]] += 1

        filteredS = []
        for i in range(len(s)):
            if s[i] in dictT:
                filteredS.append([i, s[i]])

        right = 0
        left = 0
        formed = 0
        required = len(dictT)
        windowCounts = {}
        ans = [-1, 0, 0]

        while right < len(filteredS):
            c = filteredS[right][1]
            if c not in windowCounts:
                windowCounts[c] = 1
            else:
                windowCounts[c] += 1
            
            if c in dictT and windowCounts[c] == dictT[c]:
                formed += 1
            
            while left <= right and formed == required:
                c = filteredS[left][1]

                end = filteredS[right][0]
                start = filteredS[left][0]
                if ans[0] == -1 or end - start + 1 < ans[0]:
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;

                windowCounts[c] -= 1
                if c in dictT and windowCounts[c] < dictT[c]:
                    formed -= 1
                
                left += 1
            right += 1
        
        return "" if ans[0] == -1 else s[ans[1]:ans[2] + 1]