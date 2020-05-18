class Solution {
public:
    int countTriplets (vector<int>& arr) {
        int ret = 0;
        int x, y, z;
        int arrLen = arr.size();
        for (x = 0; x < arrLen; x++) {
            int a = 0;
            for (y = x; y < arrLen; y++) {
                a ^= arr[y];
                int b = 0;
                for (z = y + 1; z < arrLen; z++) {
                    b ^= arr[z];
                    if (a == b) ret++;
                }
            }
        }
        return ret;
    }
};