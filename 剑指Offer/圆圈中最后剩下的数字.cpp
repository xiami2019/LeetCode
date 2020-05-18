/*
法一：模拟，超出时间限制；
*/
class Solution {
public:
    int lastRemaining(int n, int m) {
        queue<int> numbers;
        for (int i = 0; i < n; i++){
            numbers.push(i);
        }
        int result;
        while (!numbers.empty()){
            int temp = m - 1;
            while(temp--){
                numbers.push(numbers.front());
                numbers.pop();
            }
            result = numbers.front();
            numbers.pop();
        }
        return result;
    }
};

/*
法1变种，使用单链表代替队列
*/
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1){
            return -1;
        }

        unsigned int i = 0;

        list<int> numbers;
        for (int i = 0; i < n; i++){
            numbers.push_back(i);
        }

        typedef list<int>::iterator iter;
        iter current = numbers.begin();
        while (numbers.size() > 1){
            for (int i = 1; i < m; i++){
                current++;
                if (current == numbers.end()){
                    current = numbers.begin();
                }
            }

            iter next = ++current;
            if (next == numbers.end()){
                next = numbers.begin();
            }
            --current;
            numbers.erase(current);
            current = next;
        }
        return *current;
    }
};

/*
法二：使用数学方法
*/
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1){
            return -1;
        }

        int ans = 0;
        for (int i = 2; i <= n; i++){
            ans = (ans + m) % i;
        }
        return ans;
    }
};