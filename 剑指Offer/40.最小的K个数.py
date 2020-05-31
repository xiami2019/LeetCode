class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        def myPartation(arr: List[int], left: int, right: int) -> List[int]:
            pivot = arr[right]
            local = left - 1
            for i in range(left, right):
                if arr[i] < pivot:
                    local += 1
                    arr[local], arr[i] = arr[i], arr[local]
            local += 1
            arr[local], arr[right] = arr[right], arr[local]
            return local

        if k == 0:
            return []
        left = 0
        right = len(arr) - 1
        index = myPartation(arr, left, right)
        while index != k - 1:
            if index < k - 1:
                left = index + 1
            else:
                right = index - 1
            index = myPartation(arr, left, right)
        return arr[:index + 1]
        

class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        kNumbers = 
                