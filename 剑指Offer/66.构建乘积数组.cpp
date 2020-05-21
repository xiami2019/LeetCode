class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int aLen = a.size();
        if (aLen == 0) return vector<int>();
        vector<int> res(aLen);
        vector<int> array1(aLen);
        vector<int> array2(aLen);
        array1[0] = 1;
        array2[aLen - 1] = 1;
        for (int i = 1; i < aLen; i++) {
            array1[i] = array1[i - 1] * a[i - 1];
            array2[aLen - 1 - i] = array2[aLen - i] * a[aLen - i];
        }
        for (int i = 0; i < aLen; i++) {
            res[i] = array1[i] * array2[i];
        }
        return res;
    }
};