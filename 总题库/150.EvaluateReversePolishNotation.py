class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for token in tokens:
            if token[0].isdigit() or (len(token) > 1 and token[1].isdigit()):
                st.append(int(token))
            else:
                num2 = st[-1]
                st.pop();
                num1 = st[-1]
                st.pop();
                if token == '+':
                    num3 = num1 + num2
                if token == '-':
                    num3 = num1 - num2
                if token == '*':
                    num3 = num1 * num2
                if token == '/':
                    num3 = int(num1 / num2)
                st.append(num3)
        return st[-1]
