class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = (left + right) >> 1;
        int invCount = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);
        int i = left, j = mid + 1, pos = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i++];
                invCount += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j++];
            }
            pos++;
        }

        for (int k = i; k <= mid; k++) {
            tmp[pos++] = nums[k];
            invCount += (j - (mid + 1));
        }

        for (int k = j; k <= right; k++) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + left, tmp.begin() + right + 1, nums.begin() + left);
        return invCount;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};