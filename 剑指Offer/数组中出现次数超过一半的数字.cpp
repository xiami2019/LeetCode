class Solution {
public:
//直接拿map以空间换时间；
    int majorityElement(vector<int>& nums) {
        map<int, int> numsCounts;
        int halfNumsLen = nums.size() / 2;
        for (int i : nums){
            if (numsCounts.count(i) == 0){
                numsCounts[i] = 1;
            }
            else{
                numsCounts[i] += 1;
            }
            if (numsCounts[i] > halfNumsLen){
                return i;
            }
        }
        return 0;
    }
};

class Solution {
public:
//法2：先排序，再输出中位数；快排：nlogn；
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.begin() + nums.size());
        return nums[nums.size() / 2];
    }
};

class Solution {
public:
/*法3：分治：
如果我们知道数组左边一半和右边一半的众数，我们就可以用线性时间知道全局的众数是哪个。
算法：
使用经典的分治算法递归求解，直到所有的子问题都是长度为1的数组。由于传输子数组需要
额外的时间和空间，所以我们实际上只传输子区间的左右指针lo和hi表示相应的左右下标。
长度为1的子数组中唯一的数显然是众数，直接返回即可。如果回溯后某区间的长度大于1，我
们必须将左右区间的值合并。如果它们的众数相同，那么显然这一段区间的众数是它们相同的
值。否则我们需要比较两个众数在整个区间内出现的次数来决定该区间的众数。原问题的答案
就是下标为0和n之间的众数这一子问题。
时间复杂度：nlogn；
空间复杂度：logn；
尽管分治算法没有直接分配额外的数组空间，但因为递归的过程，在栈中使用了一些非常数的
额外空间。因为算法每次将数组从每一层的中间断开，所以数组长度变为1之前只有O(logn)次
切断。由于递归树是平衡的，所以从根到叶子结点的长度都是O(logn)。由于递归树是深度优先
的，空间复杂度等于最长的一条路径，也就是O(logn)
*/
    int countsInRange(vector<int>& nums, int num, int lo, int hi)
    {
        int counts = 0;
        for (int i = lo; i <= hi; i++){
            if (nums[i] == num){
                counts++;
            }
        }

        return counts;
    }

    int divide(vector<int>& nums, int lo, int hi)
    {
        if (lo == hi){
            return nums[lo];
        }

        int mid = (hi - lo) / 2 + lo;
        int numLeft = divide(nums, lo, mid);
        int numRight = divide(nums, mid + 1, hi);

        if (numLeft == numRight){
            return numLeft;
        }

        int leftCount = countsInRange(nums, numLeft, lo, hi);
        int rightCount = countsInRange(nums, numRight, lo, hi);

        return leftCount > rightCount ? numLeft : numRight;
    }

    int majorityElement(vector<int>& nums) 
    {
        return divide(nums, 0, nums.size() - 1);
    }
};

class Solution {
public:
/*法4: Boyer-Moore 投票算法
想法：如果我们把众数记为+1，把其他数记为-1，将它们全部加起来，显然和大于0，从结果本身我们可以看出众数比其他数多。
算法：本质上，Boyer-Moore算法就是找nums的一个后缀suf，其中suf[0]就是后缀中的众数。我们维护一个计数器，如果遇到
一个我们目前的候选众数，就将计数器加一，否则减一。只要计数器等于0，我们就将nums中之前访问的数字全部忘记，并把下
一个数字当做候选的众数。
时间复杂度：O(n)
Boyer-Moore算法严格执行了n次循环，所以时间复杂度是线性时间的。
空间复杂度：O(1)
Boyer-Moore只需要常数级别的额外空间。
*/
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int i : nums){
            if (count == 0){
                candidate = i;
                count++;
            }
            else if (candidate == i){
                count++;
            }
            else{
                count--;
            }
        }

        return candidate;
    }
};
