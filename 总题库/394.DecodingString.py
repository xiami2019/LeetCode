class Solution:
    def decodeString(self, s: str) -> str:
        times = []
        chars = []
        number = 0
        res = ''

        for i in range(len(s)):
            if '0' <= s[i] and s[i] <= '9':
                number = number * 10 + int(s[i])
            elif s[i] == ']':
                temp = ''
                final = ''
                index = len(chars) - 1
                while chars[-1] != '[':
                    temp = chars[-1] + temp
                    index -= 1
                    chars.pop()
                chars.pop()
                curTimes = times[-1]
                times.pop()
                while curTimes != 0:
                    final += temp
                    curTimes -= 1
                chars.append(final)
            else:
                if number:
                    times.append(number)
                    number = 0
                chars.append(s[i])
        for i in range(len(chars)):
            res += chars[i];

        return res