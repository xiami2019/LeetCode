class Solution:
    def calculate(self, s: str) -> int:
        st = []
        res, index, sign, sLen= 0, 0, 1, len(s)

        while index < sLen:
            if s[index].isdigit():
                num = 0
                while index < sLen and s[index].isdigit():
                    num = 10 * num + int(s[index])
                    index += 1
                index -= 1
                st.append(sign * num)
            else:
                if s[index] == '-': sign = -1
                if s[index] == '+': sign = 1
                if s[index] == '*' or s[index] == '/':
                    num1, num2, num3= st[-1], 0, 0
                    st.pop()
                    opt = s[index]
                    index += 1
                    if index == sLen: return
                    while s[index] == ' ': index += 1
                    while index < sLen and s[index].isdigit():
                        num2 = num2 * 10 + int(s[index])
                        index += 1
                    index -= 1
                    if opt == '/':
                        num3 = int(num1 / num2)
                    elif opt == '*':
                        num3 = int(num1 * num2)
                    st.append(num3)
            index += 1

        for i in st:
            res += i
        return res