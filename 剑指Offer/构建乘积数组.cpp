class Solution {
    //拆开来做动态规划
public:
    vector<int> constructArr(vector<int>& a) {
        int aLen = a.size();
        vector<int> ans(aLen, 1);
        for (int i = 1; i < aLen; i++){
            ans[i] = ans[i - 1] * a[i - 1];
        }

        int temp = 1;
        for (int i = aLen - 2; i >= 0; i--){
            temp *= a[i + 1];
            ans[i] *= temp;
        }

        return ans;
    }
};