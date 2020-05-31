class Solution {
    int myPartation(vector<int>& arr, int left, int right) {
        int pivot = arr[right], local = left - 1;
        for (int i = left; i < right; i++) {
            if (arr[i] < pivot) {
                swap(arr[++local], arr[i]);
            }
        }
        swap(arr[++local], arr[right]);
        return local;
    }

public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1
        int index = myPartation(arr, left, right);
        while (index != k - 1) {
            if (index < k - 1) {
                left = index + 1;
            }
            else {
                right = index - 1;
            }
            index = myPartation(arr, left, right)
        }
        return vector<int> (arr.begin() + left, right - left + 1);
    }
};

// 最大堆解法：
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0) return res;
        multiset<int, greater<int>> kNumbers;
        int index;
        for (index = 0; index < k; index++) {
            kNumbers.insert(arr[index]);
        }
        for (; index < arr.size(); index++) {
            if (arr[index] < *kNumbers.begin()) {
                kNumbers.erase(kNumbers.begin());
                kNumbers.insert(arr[index]);
            }
        }
        for (auto iter = kNumbers.begin(); iter != kNumbers.end(); iter++) {
            res.push_back(*iter);
        }
        return res;
    }
};