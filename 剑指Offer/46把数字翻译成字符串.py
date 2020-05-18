class Solution:
    def translateNum(self, num: int) -> int:
        if num < 0:
            return 0
        
        numStr = str(num)
        numLen = len(numStr)
        post1 = 0
        post2 = 0
        count = 0
        
        for i in range(numLen - 1, -1, -1):
            count = 0
            if i < numLen - 1:
                count = post1
                temp = int(int(numStr[i]) * 10 + int(numStr[i + 1]))
                if temp >= 10 and temp <= 25:
                    if i <numLen - 2:
                        count += post2
                    else:
                        count += 1
            else:
                count = 1
            
            post2 = post1
            post1 = count
        return post1