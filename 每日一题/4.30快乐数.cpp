/*
法一：使用hashset检测指针
*/
class Solution {
    int computeNumber(int n) {
        int res = 0;
        while (n) {
            res += pow(n % 10, 2.0);
            n /= 10;
        }
        return res;
    }

public:
    bool isHappy(int n) {
        set<int> numbers;
        int temp = n;
        while (1) {
            temp = this->computeNumber(temp);
            if (temp == 1) return true;
            if (temp == 0 || numbers.find(temp) != numbers.end()) {
                break;
            }
            numbers.insert(temp);
        }
        return false;
    }
};

/*
法二：快慢指针法
*/
class Solution {
    int getNext(int n) { // 得到下一个数
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};