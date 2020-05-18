class Solution {
    long long dpTable[310][310];
public:
    int countTriplets(vector<int>& arr) {
        for (int i = 0; i < 310; i++) {
            for (int j = 0; j < 310; j++) {
                dpTable[i][j] = -1;
            }
        }

        int ans = 0, arrLen = arr.size();
        if (arrLen <= 1) return ans;

        for (int i = 0; i < arrLen - 1; i++) {
            for (int k = i + 1; k < arrLen; k++) {
                for (int j = i + 1; j <= k; j++) {
                    long long leftSum = 0, rightSum = 0;

                    if (dpTable[j][k] == -1) {
                        for (int p = j; p < k + 1; p++) {
                            rightSum ^= arr[p];
                        }
                        dpTable[j][k] = rightSum;
                    }
                    else {
                        rightSum = dpTable[j][k];
                    }

                    if (dpTable[i][j - 1] == -1) {
                        for (int p = i; p < j; p++) {
                            leftSum ^= arr[p];
                        }
                        dpTable[i][j - 1] = leftSum;
                    }
                    else {
                        leftSum = dpTable[i][j - 1];
                    }

                    if (leftSum == rightSum) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};