class Solution {
public:
    vector<int> printNumbers(int n) {
        int maxNumber = pow(10, n);
        vector<int> result;
        for (int i = 1; i < maxNumber; i++){
            result.push_back(i);
        }
        return result;
    }
};