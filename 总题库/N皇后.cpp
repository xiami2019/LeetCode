class Solution {
    vector<vector<string>> res;
    void backtrack(vector<int>& solu, int col, int n) {
        if (col == n) {
            vector<string> s;
            for (int i = 0; i < n; i++) {
                string temp = "";
                for (int j = 0; j < n; j++) {
                    temp += ".";
                }
                temp[solu[i]] = 'Q';
                s.emplace_back(temp);
            }
            res.emplace_back(s);
            return;
        }

        for (int i = 0; i < n; i++) {
            bool flag = true;
            // 判断是否位于同一对角线
            for (int j = 0; j < col; j++){
                if (solu[j] == i || j - col == solu[j] - i || j - col == i - solu[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                solu[col] = i;
                this->backtrack(solu, col + 1, n);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> solu(n);
        for (int i = 0; i < n; i++) {
            solu[0] = i;
            this->backtrack(solu, 1, n);
        }

        return res;
    }
};