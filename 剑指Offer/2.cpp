/*
二维数组的查找（左下角标志数法）
此类矩阵中左下角和右上角元素有特殊性，称为标志数；
左下角元素：为所在列最大元素，所在行最小元素。
右上角元素：为所在行最大元素，所在列最小元素。
标志数性质：将matrix中的左下角元素（标志数）记作flag，则由：
1.若flag > target，则target一定在flag所在行的上方。
2.若flag < target，则target一定在flag所在列的右方。
算法流程：根据以上性质。设计算法在每轮对比时消去一行（列）元素，以降低时间复杂度。
1.从矩阵matrix左下角元素开始遍历，并与目标值对比：
2.若行索引或列索引越界，则代表矩阵中无目标值。
算法本质：每轮i或j移动后，相当于生成了“消去一行（列）的新矩阵”，索引（i, j）指向新矩阵的左下角元素（标志数）
，因此可重复使用以上性质消去行（列）
复杂度分析：
时间复杂度O（M+N）：其中，N和M分别为矩阵行数和列数，此算法最多循环M+N次。
空间复杂度O（1）：i，j指针使用常数大小额外空间。
*/

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

