/*
反复左移+按位与
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag = 1;
        int count = 0;
        while (flag) {
            if (n & flag) {
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }
};

/*
法二：
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n) {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
};