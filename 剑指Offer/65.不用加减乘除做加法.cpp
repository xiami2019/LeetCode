class Solution {
public:
    int add(int a, int b) {
        int sum = 0, carry = 0;
        do {
            sum = a ^ b;
            carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }
        while (carry != 0);

        return sum;
    }
};