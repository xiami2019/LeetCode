class Solution:
    def __init__(self):
        self.num2str = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

    def combine(self, res: List[int], cur: str, digits: str, start: int):
        if start == len(digits) - 1 :
            for c in self.num2str[int(digits[start]) - 2]:
                res.append(cur + c)
        else:
            for c in self.num2str[int(digits[start]) - 2]:
                self.combine(res, cur + c, digits, start + 1)

    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        res = []
        cur = ''
        self.combine(res, cur, digits, 0)
        return res