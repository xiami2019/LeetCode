/*
法一：二分查找；
由于x平方根的整数部分ans是满足k^2 <= x的最大k值，因此我们可以对k进行二分查找，从而得到答案。

二分查找的下界为0，上界可以粗略地设定为x。在二分查找的每一步中，我们只需要比较中间元素mid的平方
与x的大小关系，并通过比较的结果调整上下的范围。由于我们所有的运算都是整数运算，不会存在误差，因此
在得到最终的答案ans后，也就不需要再去尝试ans+1了
*/

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

/*
法二：牛顿迭代；
*/
class Solution {
public:
    int mySqrt(int x) {
        
    }
};