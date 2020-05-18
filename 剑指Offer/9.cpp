class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty()) return 0;
        int minNumber = numbers[numbers.size() - 1];
        for (int i = numbers.size() - 1; i >= 0; i--){
            if (numbers[i] <= minNumber){
                minNumber = numbers[i];
            }
            else break;
        }
        return minNumber;
    }
};