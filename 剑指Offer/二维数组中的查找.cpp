// 每次选取右上角或者左下角的数字
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        if (matrix[0][0] == target) return true;
        int i = matrix.size() - 1, j = 0, y = matrix[0].size(), x = matrix.size();
        int flag = matrix[i][j];
        while (1){
            if (target > flag){
                j++;
            }
            else if (target < flag){
                i--;
            }

            if (i < 0 || j >= y){
                break;
            }
            if (target == matrix[i][j]){
                return true;
            }
            else{
                flag = matrix[i][j];
            }
        }
        return false;
    }
};