class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> numberSet;
        for (int i: nums){
            if (numberSet.find(i) == numberSet.end()){
                numberSet.insert(i);
            }
            else{
                return i;
            }
        }
        return 0;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int allNumbers[100000] = {0};
        for (int i: nums){
            if (allNumbers[i] == 0){
                allNumbers[i] = 1;
            }
            else{
                return i;
            }
        }
        return 0;
    }
};