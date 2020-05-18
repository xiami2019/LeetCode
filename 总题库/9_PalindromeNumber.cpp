class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp_x = x;
        long long x_reverse = 0;
        for(; temp_x; x_reverse = x_reverse * 10 + temp_x % 10, temp_x /= 10);
        if(x_reverse == x) return true;
        else return false;
    }
};