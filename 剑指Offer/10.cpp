/*
广度优先搜索无法处理具有顺序要求的序列，所以使用深度优先搜索来处理；
*/
int addition_x[] = {0, 0, 1, -1};
int addition_y[] = {1, -1, 0, 0};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (word.size() == 1){
                        return true;
                    }
                    board[i][j] = ' ';
                    if (dfs(make_pair(i, j), board, word.substr(1))){
                        return true;
                    }
                    else{
                        board[i][j] = word[0];
                    }
                }
            }
        }
        return false;
    }

    bool dfs(pair<int, int> node, vector<vector<char>>& board, string word){
        for (int i = 0; i < 4; i++){
            int newX = node.first + addition_x[i], newY = node.second + addition_y[i];
            if (newX < 0 || newX >= board.size() || newY < 0 || newY >= board[0].size()){
                continue;
            }
            else if (board[newX][newY] == word[0]){
                if (word.size() == 1){
                    return true;
                }
                board[newX][newY] = ' ';
                if (dfs(make_pair(newX, newY), board, word.substr(1))){
                    return true;
                }
                else{
                    board[newX][newY] = word[0];
                }
            }
        }
        return false;
    }
};