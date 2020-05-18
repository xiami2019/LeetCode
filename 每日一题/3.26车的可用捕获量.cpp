class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y;
        int ans = 0;
        int row = board.size(), column = board[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if (board[i][j] == 'R'){
                    x = i, y = j;
                }
            }
        }
        int left = x - 1, right = x + 1, up = y - 1, down = y + 1;
        while (left >= 0 || right < row || up >= 0 || down < column){
            if (left >= 0){
                if (board[left][y] == 'p'){
                    ans++;
                    left = -1;
                }
                else if (board[left][y] == 'B'){
                    left = -1;
                }
                else{
                    left--;
                }
            }
            if (right < row){
                if (board[right][y] == 'p'){
                    ans++;
                    right = row;
                }
                else if (board[right][y] == 'B'){
                    right = row;
                }
                else{
                    right++;
                }
            }
            if (up >= 0){
                if (board[x][up] == 'p'){
                    ans++;
                    up = -1;
                }
                else if (board[x][up] == 'B'){
                    up = -1;
                }
                else{
                    up--;
                }
            }
            if (down < column){
                if (board[x][down] == 'p'){
                    ans++;
                    down = column;
                }
                else if (board[x][down] == 'B'){
                    down = column;
                }
                else{
                    down++;
                }
            }
        }
        return ans;
    }
};