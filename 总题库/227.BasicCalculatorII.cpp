class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1, sLen = s.size(), res = 0;
        for (int i = 0; i < sLen; ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < sLen && isdigit(s[i])) {
                    num = 10 * num + s[i] - '0';
                    i++;
                }
                i--;
                st.push(sign * num);
            }
            else {
                if (s[i] == '+') sign = 1;
                if (s[i] == '-') sign = -1;
                if (s[i] == '/' || s[i] == '*') {
                    char opt = s[i];
                    int num1 = st.top(), num2 = 0, num3 = 0;
                    st.pop();
                    i++;
                    if (i == sLen) return 0; // 输入出错
                    while (i < sLen && (isdigit(s[i]) || s[i] == ' ')) {
                        num2 = 10 * num2 + s[i] - '0';
                        i++;
                    }
                    i--;
                    if (opt == '/') {
                        num3 = num1 / num2;
                    }
                    else if (opt == '*') {
                        num3 = num1 * num2;
                    }
                    st.push(num3);
                }
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5