class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def isValid(s: str) -> bool:
            cnt = 0
            for character in s:
                if character == '(':
                    cnt += 1
                elif character == ')':
                    if cnt < 1: return False
                    else:
                        cnt -= 1
            return cnt == 0
        
        level = {s}
        while level:
            valid = list(filter(isValid, level))
            if valid: return valid
            nextLevel = set()

            for item in level:
                for i in range(len(item)):
                    if item[i] in '()':
                        nextLevel.add(item[:i] + item[i + 1:])
            level = nextLevel