class Solution {
    int addX[4] = {0, 0, 1, -1};
    int addY[4] = {1, -1, 0, 0};

    bool backtrack(vector<vector<char>>& board, int x, int y, string word) {
        if (word == "") return true;
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < 4; i++) {
            int newX = x + addX[i], newY = y + addY[i];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && board[newX][newY] == word[0]) {
                char temp = board[newX][newY];
                board[newX][newY] = '\0';
                if (backtrack(board, newX, newY, word.substr(1))) {
                    return true;
                }
                board[newX][newY] = temp;
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
                    board[i][j] = '\0';
                    if (backtrack(board, i, j, word.substr(1))) return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};