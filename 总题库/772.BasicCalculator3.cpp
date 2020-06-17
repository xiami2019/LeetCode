class Solution {
public:
    int calculate(string s) {
        stack<long> st;
        int sLen = s.size();
        long res = 0, num = 0;
        char op = '+';

        for (int i = 0; i < sLen; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                while (i < sLen && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
            }
            else if (ch == '(') {
                int j = i, cnt = 0;
                for (j; i < sLen; ++i) {
                    if (s[i] == '(') {
                        ++cnt;
                    }
                    if (s[i] == ')') {
                        --cnt;
                    }
                    if (cnt == 0) {
                        num = calculate(s.substr(j + 1, i - j - 1));
                        break;
                    }
                }
            }
            if (ch < '0' && ch != ' ' || i == sLen - 1) {
                if (op == '+') {
                    st.push(num);
                }
                else if (op == '-') {
                    st.push(-num);
                }
                else if (op == '*' || op == '/') {
                    long tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = ch;
                num = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

/*
"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
*/