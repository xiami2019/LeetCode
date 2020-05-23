class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if len(numbers) == 1:
            return numbers[0]

        left = 0
        right = len(numbers) - 1

        while left <= right:
            if numbers[right] > numbers[left]:
                return numbers[left]
            middle = (left + right) >> 1
            if numbers[right] == numbers[left] and numbers[middle] == numbers[left]:
                for i in range(left, right):
                    if numbers[i] > numbers[i + 1]:
                        return numbers[i + 1]
                return numbers[left]
            elif middle > 0 and numbers[middle - 1] > numbers[middle]:
                return numbers[middle]
            elif numbers[middle] <= numbers[right]:
                right = middle - 1
            else:
                left = middle + 1
        return 0