// Binary Search
class Solution {
public:
    // 选择一个阈值value，使得它对应的sum是最后一个小于等于target的阈值，那么目标值可能在value也可能在value + 1；
    int findBestValue(vector<int>& arr, int target) {
        int left = 0;
        int right = 0;
        
        for (int num : arr) {
            right = max(right, num);
        }

        while (left < right) {
            int mid = (right - left + 1) / 2 + left;
            int sum = calculateSum(arr, mid);
            // 计算最后1个使得转变以后数组的和小于等于target的阈值threshold
            if (sum > target) {
                // 大于等于的就不是解，threshold太大了，下一轮搜索区间就是[left, mid - 1]
                right = mid - 1;
            }
            else {
                // 下一轮搜索区间[mid, right]
                left = mid;
            }
        }

        // 比较阈值线分别定在left和left+1的时候与target的接近程度
        int sum1 = calculateSum(arr, left);
        int sum2 = calculateSum(arr, left + 1);
        
        if (abs(target - sum1) <= abs(sum2 - target)) {
            return left;
        }
        return left + 1;
    }

    int calculateSum(vector<int>& arr, int threshold) {
        int sum = 0;
        for (int num : arr) {
            sum += min(num, threshold);
        }
        return sum;
    }
};

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        if (arr.size() == 0) {
            return 0;
        }
        sort(arr.begin(), arr.end());
        int sum = 0, arrSize = arr.size();
        for (int i = 0; i < arrSize; ++i) {
            int x = (target - sum) / (arrSize - i);
            if (x < arr[i]) {
                double t = ((double)(target - sum)) / (arr.size() - i);
                if (t - x > 0.5) {
                    return x + 1;
                }
                else {
                    return x;
                }
            }
            sum += arr[i];
        }
        return arr[arrSize - 1];
    }
};