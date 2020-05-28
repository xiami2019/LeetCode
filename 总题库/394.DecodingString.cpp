class Solution {
public:
    string decodeString(string s) {
        stack<int> times;
        vector<string> chars;
        int number = 0;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == ']') {
                string temp = "", final = "";
                int index = chars.size() - 1;
                while (chars.back() != "[") {
                    temp = chars.back() + temp;
                    index--;
                    chars.pop_back();
                }
                chars.pop_back();
                // reverse(temp.begin(), temp.end());
                int curTimes = times.top();
                times.pop();
                while (curTimes--) {
                    final += temp;
                }
                chars.emplace_back(final);
            }
            else {
                if (number) {
                    times.push(number);
                    number = 0;
                }
                string temp = "";
                chars.push_back(temp + s[i]);
            }
        }
        for (int i = 0; i < chars.size(); i++) {
            res += chars[i];
        }
        return res;
    }
};