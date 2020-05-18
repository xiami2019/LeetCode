class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int> > result;
        int indexHead = 1, indexTail = 1, subSum = 1;

        while (indexHead <= target - 1){
            if (subSum == target){
                vector<int> temp(indexHead - indexTail + 1);
                for (int i = indexTail; i <= indexHead; i++){
                    temp[i - indexTail] = i;
                }
                result.push_back(temp);
                indexHead++;
                subSum += indexHead;
            }
            else if (subSum < target){
                indexHead++;
                subSum += indexHead;
            }
            else if (subSum > target){
                subSum -= indexTail;
                indexTail++;
            }
        }
        return result;
    }
};