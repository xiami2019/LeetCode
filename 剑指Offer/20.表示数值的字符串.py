class Solution:
    def isNumber(self, s: str) -> bool:
        if len(s) == 0:
            return False

        index = 0
        while index < len(s) and s[index] == ' ':
            index += 1
        s = s[index:]
        index = len(s) - 1
        while index >= 0 and s[index] == ' ':
            index -= 1
        s = s[:index + 1]

        e = False
        number = False
        point = False
        numberAfterE = True

        for i in range(len(s)):
            if s[i] >= '0' and s[i] <= '9':
                number = True
                numberAfterE = True
            elif s[i] == '.':
                if e or point:
                    return False
                point = True
            elif s[i] == 'e':
                if e or number is False:
                    return False
                numberAfterE = False
                e = True
            elif s[i] == '-' or s[i] == '+':
                if i != 0 and s[i - 1] != 'e':
                    return False
            else:
                return False

        return number and numberAfterE

        