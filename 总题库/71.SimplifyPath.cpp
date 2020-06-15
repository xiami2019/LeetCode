class Solution {
public:
    string simplifyPath(string path) {
        vector<string> allNames;
        stack<string> s;
        string temp = "";
        int index = 1;
        while (index < path.size()) {
            if (path[index] == '/') {
                if (temp != "") {
                    allNames.push_back(temp);
                    temp = "";
                }
                ++index;
            }
            else {
                temp += path[index];
                ++index;
            }
        }
        if (temp != "") allNames.push_back(temp);

        for (const string& str : allNames) {
            if (str == ".") continue;
            if (str == "..") {
                if (!s.empty()) s.pop();
                continue;
            }
            s.push(str);
        }

        string res = "";
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res == "" ? "/" : res;
    }
};