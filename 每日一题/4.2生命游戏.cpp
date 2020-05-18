class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> > temp = board;
        int addX[8] = {0, 0, -1, 1, 1, 1, -1, -1};
        int addY[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int row = (int)temp.size(), column = (int)temp[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                int liveCells = 0;
                for (int k = 0; k < 8; k++){
                    int newX = i + addX[k], newY = j + addY[k];
                    if (newX >= 0 && newX < row && newY >= 0 && newY < column){
                        if (temp[newX][newY] == 1){
                            liveCells++;
                        }
                    }
                }
                if (temp[i][j] == 1 && liveCells < 2){
                    board[i][j] = 0;
                    continue;
                }
                if (temp[i][j] == 1 && (liveCells == 2 || liveCells == 3)){
                    continue;
                }
                if (temp[i][j] == 1 && liveCells > 3){
                    board[i][j] = 0;
                    continue;
                }
                if (temp[i][j] == 0 && liveCells == 3){
                    board[i][j] = 1;
                    continue;
                }
            }
        }
    }
};

/*
in-place算法，引入新的状态；
0表示死亡；
1表示存活；
2表示下一回合产生；
3表示下一回合死亡；
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int addX[8] = {0, 0, -1, 1, 1, 1, -1, -1};
        int addY[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int row = (int)board.size(), column = (int)board[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                int liveCells = 0;
                for (int k = 0; k < 8; k++){
                    int newX = i + addX[k], newY = j + addY[k];
                    if (newX >= 0 && newX < row && newY >= 0 && newY < column){
                        if (board[newX][newY] == 1 || board[newX][newY] == 3){
                            liveCells++;
                        }
                    }
                }
                if (board[i][j] == 1 && liveCells < 2){
                    board[i][j] = 3;
                    continue;
                }
                if (board[i][j] == 1 && (liveCells == 2 || liveCells == 3)){
                    continue;
                }
                if (board[i][j] == 1 && liveCells > 3){
                    board[i][j] = 3;
                    continue;
                }
                if (board[i][j] == 0 && liveCells == 3){
                    board[i][j] = 2;
                    continue;
                }
            }
        }
        //更新一遍
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if (board[i][j] == 2){
                    board[i][j] = 1;
                }
                if (board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};