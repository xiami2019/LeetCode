// 递归写法，可能会超时，存在重复计算

class Solution {
private:
    int maxValue = 6;
    void probability(int number, vector<int>& pProbabilities) {
        for (int i = 1; i <= maxValue; ++i) {
            probability(number, number, i, pProbabilities);
        }
    }

    void probability(int original, int current, int sum, vector<int>& pProbabilities) {
        if (current == 1) {
            pProbabilities[sum - original]++;
        }
        else {
            for (int i = 1; i <= maxValue; ++i) {
                probability(original, current - 1, i + sum, pProbabilities);
            }
        }
    }
public:
    vector<double> twoSum(int n) {
        if (n < 1) return vector<double>();
        int maxSum = n * maxValue;
        vector<int> pProbabilities(maxSum - n + 1);
        vector<double> ans(maxSum - n + 1);
        probability(n, pProbabilities);
        int total = pow(6, n);
        for (int i = n; i <= maxSum; ++i) {
            ans[i - n] = (double)pProbabilities[i - n] / total;
        }
        return ans;
    }
};

// 迭代写法

class Solution {
    int maxValue = 6;
public:
    vector<double> twoSum(int n) {
        if (n < 1) return vector<double>();

        vector<vector<int>> pProbabilities(2, vector<int>(maxValue * n + 1));

        int flag = 0;
        for (int i = 1; i <= maxValue; ++i) {
            pProbabilities[flag][i] = 1;
        }
        
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < k; i++) {
                pProbabilities[1 - flag][i] = 0;
            }
            for (int i = k; i <= maxValue * k; i++) {
                pProbabilities[1 - flag][i] = 0;
                for (int j = 1; j <= maxValue && j <= i; j++) {
                    pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
                }
            }
            flag = 1 - flag;
        }
        vector<double> ans(maxValue * n - n + 1);
        int total = pow(6, n);
        for (int i = n; i <= maxValue * n; i++) {
            ans[i - n] = (double)pProbabilities[flag][i] / total;
        }
        return ans;
    }
};