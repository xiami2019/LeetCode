class Solution:
    def replaceSpace(self, s: str) -> str:
        numberOfBlanks = 0
        for c in s:
            if c == ' ':
                numberOfBlanks += 1

        totalLength = len(s) + numberOfBlanks * 2
        newStr = [' '] * totalLength
        # newStr = ' ' * totalLength
        index = totalLength - 1

        for i in range(len(s) - 1, -1, -1):
            if s[i] != ' ':
                newStr[index] = s[i]
                index -= 1
            else:
                newStr[index] = '0'
                newStr[index - 1] = '2'
                newStr[index - 2] = '%'
                index = index - 3

        return ''.join(newStr)