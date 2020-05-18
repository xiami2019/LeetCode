/*
动态规划解法
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int tempSum = 0;
        for (int i : nums) {
            if (tempSum >= 0) {
                tempSum += i;
            }
            else {
                tempSum = i;
            }
            ans = max(ans, tempSum);
        }
        return ans;
    }
};

/*
分治解法：
我们定义一个操作get(a, l, r)表示查询a序列[l, r]区间内的最大字段和，那么最终我们要求的答案就是
get(nums, 0, nums.size() - 1)。

如何实现分治这个操作？
对一个区间[l, r]，我们取m = (l + r) / 2，对区间[l, m]和[m + 1, r]分治求解。当递归逐层深入直到
区间长度缩小为1的时候，递归[开始回升]。这个时候考虑如何通过[l, m]区间的信息和[m + 1, r]区间的
信息合并成区间[l, r]的信息。

我们要维护区间的哪些信息？
我们如何合并这些信息？

对一个区间[l, r]，可以维护四个量：
lSum表示[l,r]内以l为左端点的最大字段和
rSum表示[l,r]内以r为右端点的最大字段和
mSum表示[l,r]内的最大字段和
iSum表示[l,r]的区间和

方法二相较于方法一来说，时间复杂度相同，但是因为使用了递归，并且维护了四个信息的结构体，运行的时间
略长，空间复杂度也不如方法一优秀，而且难以理解。那么这种方法存在的意义是什么呢？

但是方法二不仅可以解决区间[0, n - 1]，还可以用于解决任意的子区间[l, r]的问题。如果我们把[0, n - 1]
分治下去出现的所有子区间的信息都用堆栈存储的方式记忆化下来，即建成一颗真正的树之后，我们就可以在O(logn)
的时间内求到任意区间的答案，我们甚至可以修改序列中的值，做一些简单的维护，之后仍然可以在O(logn)的时间内
求到任意区间内的答案，对于大规模查询的情况下，这种方法的优势便体现了出来。这棵树就是被称为线段树的数据结构。
*/
class Solution {
public:
    struct Status {
        int leftSum, rightSum, mSum, iSum;
    };

    Status pushUp(Status left, Status right) {
        int iSum = left.iSum + right.iSum;
        int leftSum = max(left.leftSum, left.iSum + right.leftSum);
        int rightSum = max(right.rightSum, right.iSum + left.rightSum);
        int mSum = max(max(left.mSum, right.mSum), left.rightSum + right.leftSum);
        return (Status){leftSum, rightSum, mSum, iSum};
    }

    Status get(vector<int>& a, int left, int right) {
        if (left == right) return (Status) {a[left], a[left], a[left], a[left]};
        int m = (left + right) >> 1;
        Status leftSub = get(a, left, m);
        Status rightSub = get(a, m + 1, right);
        return pushUp(leftSub, rightSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};