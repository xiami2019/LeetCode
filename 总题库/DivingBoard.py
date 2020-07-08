class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        res = []
        if k == 0:
            return res
        tempLen = shorter * k
        res.append(tempLen)
        if shorter == longer:
            return res

        for i in range(1, k + 1):
            res.append(tempLen + i * (longer - shorter))
        return res