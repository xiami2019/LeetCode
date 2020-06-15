class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0 for _ in range(n)]
        s = []
        preTimeStamp = 0
        for log in logs:
            log = log.split(':')
            threadId = int(log[0])
            action = str(log[1])
            timeStamp = int(log[2])

            if action == 'start':
                if len(s):
                    res[s[-1]] += timeStamp - preTimeStamp
                preTimeStamp = timeStamp
                s.append(threadId)
            else:
                res[s[-1]] += timeStamp - preTimeStamp + 1
                preTimeStamp = timeStamp + 1
                s.pop()
        return res