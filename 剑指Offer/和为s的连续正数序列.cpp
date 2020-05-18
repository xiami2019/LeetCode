class Solution {
    //暴力法；
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int> > result;
        
        for (int i = 1; i < target; i++){
            int subSum = i;
            vector<int> temp;
            temp.push_back(i);
            for (int j = i + 1; j < target; j++){
                subSum += j;
                temp.push_back(j);
                if (subSum == target){
                    result.push_back(temp);
                    break;
                }
                if (subSum > target){
                    break;
                }
            }
        }

        return result;
    }
};

class Solution {
    //滑动窗口法
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int> > result;
        int indexHead = 1, indexTail = 1;
        int subSum = 1;
        // vector<int> temp;
        // temp.push_back(1);
        
        while (indexHead <= target - 1){
            if (subSum == target){
                vector<int> temp;
                for (int i = indexTail; i <= indexHead; i++){ //vector的push_back操作时最快的;
                    temp.push_back(i);
                }
                result.push_back(temp);
                indexHead++;
                subSum += indexHead;
                // temp.push_back(indexHead);
            }
            else if (subSum < target){
                indexHead++;
                subSum += indexHead;
                // temp.push_back(indexHead);
            }
            else if (subSum > target){
                subSum -= indexTail;
                indexTail++;
                // temp.erase(temp.begin());
            }
        }

        return result;
    }
};