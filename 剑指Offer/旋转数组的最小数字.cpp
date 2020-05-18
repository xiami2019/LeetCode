class Solution {
    int FindInOrder(vector<int>& numbers, int index1, int index2) {
        int result = numbers[index1];
        for (int i = index1 + 1; i < index2; i++) {
            if (result > numbers[i]) {
                result = numbers[i];
            }
        }
        return result;
    }
public:
    int minArray(vector<int>& numbers) {
        int numbersLen = numbers.size();
        if (numbersLen == 0) return 0;
        int index1 = 0, index2 = numbersLen - 1;
        int indexMid = index1;
        while (numbers[index1] >= numbers[index2]) {
            // 第一个数字大于等于最后一个数字，特殊情况除外（旋转了零个数字）
            if (index2 - index1 == 1) {
                indexMid = index2; // 两个数字相邻，此时index2即为最小的数字
                break;
            }

            indexMid = (index1 + index2) / 2;
            // 如果index1，index2，indexMid指向的三个数字相等，则只能进行顺序查找(包含了只有一个元素的情况)
            if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid]) {
                return this->FindInOrder(numbers, index1, index2);
            }

            if (numbers[indexMid] >= numbers[index1]) {
                // 最小的数在右边；
                index1 = indexMid;
            }
            else if (numbers[indexMid] <= numbers[index2]) {
                index2 = indexMid;
            }
        }
        return numbers[indexMid];
    }
};