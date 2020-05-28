class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int i : A) {
            sum += i;
            int modulus = (sum % K + K) % K;
            ++record[modulus];
        }

        for (auto [x, cx]: record) {
            ans += cx * (cx - 1) / 2; // 选出两个的组合；
        }
        return ans;
    }
};