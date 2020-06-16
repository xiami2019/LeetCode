class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        low, high = 0, 0
        for i in arr:
            high = max(high, i)
        
        while low < high:
            mid = (high - low + 1) // 2 + low
            tempSum = self.calculateSum(arr, mid)
            if tempSum > target:
                high = mid - 1
            else:
                low = mid
        
        sum1 = self.calculateSum(arr, low)
        sum2 = self.calculateSum(arr, low + 1)
        if abs(sum1 - target) <= abs(sum2 - target):
            return low
        return low + 1


    def calculateSum(self, arr, threshold):
        s = 0
        for i in arr:
            if i > threshold:
                s += threshold
            else:
                s += i
        return s