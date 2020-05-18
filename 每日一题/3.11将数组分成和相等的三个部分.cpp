class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int a : A){
            sum += a;
        }

        if (sum % 3 != 0) return false;
        int arraySize = A.size(), cuttingPoint = sum / 3, count = 0;
        sum = 0;
        for (int i = 0; i < arraySize; i++){
            sum += A[i];
            if (sum == cuttingPoint){
                sum = 0;
                count++;
            }
        }

        if (count >= 3) return true;
        else return false;
    }
};