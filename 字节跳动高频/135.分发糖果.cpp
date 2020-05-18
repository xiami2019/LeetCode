/*
法一：暴力：
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratingsLen = ratings.size();
        vector<int> candies(ratingsLen, 1);
        bool flag = true;
        int sum = 0;
        while (flag) { // 持续扫描，直到没有变动时停止循环
            flag = false;
            for (int i = 0; i < ratingsLen; i++) {
                if (i != ratingsLen - 1 && ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                    candies[i] = candies[i+1] + 1;
                    flag = true;
                }
                if (i > 0 && ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]) {
                    candies[i] = candies[i-1] + 1;
                    flag = true;
                }
            }
        }
        for (int candy: candies) {
            sum += candy;
        }
        return sum;
    }
};

/*
法二：用两个数组
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratingsLen = ratings.size();
        vector<int> left2right(ratingsLen, 1);
        vector<int> right2left(ratingsLen, 1);
        int sum = 0;
        for (int i = 1; i < ratingsLen; i++) {
            if (ratings[i] > ratings[i-1]) {
                right2left[i] = right2left[i-1] + 1;
            }
        }

        for (int i = ratingsLen - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                left2right[i] = left2right[i+1] + 1;
            }
        }
        for (int i = 0; i < ratingsLen; i++) {
            sum += max(right2left[i], left2right[i]);
        }
        return sum;
    }
};

/*
法三：（方法二的优化）使用一个数组
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratingsLen = ratings.size();
        vector<int> candies(ratingsLen, 1);
        int sum = 0;
        for (int i = 1; i < ratingsLen; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        for (int i = ratingsLen - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        for (int i = 0; i < ratingsLen; i++) {
            sum += candies[i];
        }
        return sum;
    }
};

/*
法四：常数空间一次遍历
*/
class Solution {
    int count(int n) {
        return (n * (n + 1)) / 2;
    }

public:
    int candy(vector<int>& ratings) {
        int ratingsLen = ratings.size();
        if (ratingsLen <= 1) return ratingsLen;
        int candies = 0;
        int up = 0; // 表示上坡的点数
        int down = 0; // 表示下坡的点数
        int oldSlope = 0; // 上一个点的坡度：1表示上升坡，-1表示下降坡，0表示平坡
        for (int i = 1; i < ratingsLen; i++) {
            int newSlope = ratings[i] > ratings[i-1] ? 1 : (ratings[i] < ratings[i-1] ? -1 : 0);
            if ((oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >=0 )) {
                candies += count(up) + count(down) + max(up, down); // max(up, down)代表了峰顶
                // 因为中间的谷底要算两次，所以峰顶的一就不加了
                up = 0;
                down = 0;
            }
            if (newSlope > 0) { // 上升坡
                up++;
            }
            if (newSlope < 0) { // 下降坡
                down++;
            }
            if (newSlope == 0) {
                candies++;
            }
            oldSlope = newSlope;
        }
        candies += count(up) + count(down) + max(up, down) + 1;
        return candies;
    }
};