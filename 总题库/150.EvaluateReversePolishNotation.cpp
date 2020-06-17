class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (isdigit(token[0])) {
                st.push(stoi(token));
            }
            else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int num3;
                if (token == "+") num3 = num1 + num2;
                if (token == "-") num3 = num1 - num2;
                if (token == "*") num3 = num1 * num2;
                if (token == "/") num3 = num1 / num2;
                st.push(num3); 
            }
        }
        return st.top();
    }
};