// 使用变种的二分查找
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        if (numbers.size() == 1) return numbers[0];

        while (left <= right) {
            if (numbers[right] > numbers[left]) return numbers[left];
            int middle = (left + right) >> 1;
            if (numbers[left] == numbers[right] && numbers[middle] == numbers[left]) {
                for (int i = left; i < right - 1; ++i) {
                    if (numbers[i] > numbers[i + 1]) {
                        return numbers[i + 1];
                    }
                }
                return numbers[left];
            }
            else if (middle > 0 && numbers[middle - 1] > numbers[middle]) {
                return numbers[middle];
            }
            else if (numbers[middle] <= numbers[right]) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return 0;
    }
};

