/*
维护一个k个元素的最小堆；
*/
class Solution {
    void minHeapify(vector<int>& nums, int i, int len) {
        for (; (i << 1) + 1 <= len;) {
            int lson = (i << 1) + 1;
            int rson = (i << 1) + 2;
            int small;
            if (lson <= len && nums[lson] < nums[i]) {
                small = lson;
            }
            else {
                small = i;
            }
            if (rson <= len && nums[rson] < nums[small]) {
                small = rson;
            }
            if (small != i) {
                swap(nums[i], nums[small]);
                i = small;
            }
            else break;
        }
    }

    void buildMinHeap(vector<int>& nums, int len) {
        for (int i = len / 2; i >= 0; i--) {
            minHeapify(nums, i, len);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int numsLen = nums.size();
        vector<int> topk(nums.begin(), nums.begin() + k);
        this->buildMinHeap(topk, k - 1);
        for (int i = k; i < numsLen; i++) {
            if (nums[i] >= topk[0]) {
                swap(nums[i], topk[0]);
                minHeapify(topk, 0, k - 1);
            }
        }

        return topk[0];
    }
};

/*
法二：用partition法
*/
class Solution {
    int myPartition(vector<int>& nums, int low, int high) {
        int pivot = nums[high], local = low - 1;
        for (int i = low; i < high; i++) {
            if (nums[i] > pivot) {
                swap(nums[++local], nums[i]);
            }
        }
        swap(nums[++local], nums[high]);
        return local;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1;
        int middle = this->myPartition(nums, low, high);
        while (middle != k - 1) {
            if (middle > k - 1) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
            middle = this->myPartition(nums, low, high);
        }

        return nums[middle];
    }
};