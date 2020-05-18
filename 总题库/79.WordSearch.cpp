class Solution {
    int addX[4] = {1, -1, 0, 0};
    int addY[4] = {0, 0, 1, -1};

    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y) {
        if (index == word.length()) return true;

        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < 4; i++) {
            int newX = x + addX[i], newY = y + addY[i];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                if (board[newX][newY] == word[index]) {
                    char temp = board[newX][newY];
                    board[newX][newY] = ' ';
                    if (dfs(board, word, index + 1, newX, newY)) return true;
                    board[newX][newY] = temp;
                }
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = ' ';
                    if (dfs(board, word, 1, i, j)) return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};