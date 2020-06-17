class Solution:
    def calculate(self, s: str) -> int:
        st = []
        res = 0
        sLen = len(s)
        sign = 1
        i = 0

        while i < sLen:
            num = 0
            if s[i].isdigit():
                while i < sLen and s[i].isdigit():
                    num = 10 * num + int(s[i])
                    i += 1
                i -= 1
            res += num * sign
            if s[i] == '-': sign = -1
            if s[i] == '+': sign = 1
            if s[i] == '(':
                st.append(res)
                st.append(sign)
                res, sign = 0, 1
            if s[i] == ')':
                res *= st[-1]
                st.pop()
                res += st[-1]
                st.pop()
            i += 1
        
        return res