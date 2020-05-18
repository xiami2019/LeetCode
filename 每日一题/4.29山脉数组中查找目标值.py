# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def binarySearch(self, target: int, mountain_arr: 'MountainArray', left: int, right: int, convert: 'function') -> int:
        target = convert(target)
        while left <= right:
            mid = (left + right) >> 1
            midEle = convert(mountain_arr.get(mid))
            if midEle == target:
                return mid
            elif midEle < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1

    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        arrLen = mountain_arr.length()
        left = 0
        right = arrLen - 1
        while left < right:
            mid = (left + right) >> 1;
            if mountain_arr.get(mid) < mountain_arr.get(mid + 1):
                left = mid + 1
            else:
                right = mid
        
        peak = left
        index = self.binarySearch(target, mountain_arr, 0, peak, lambda x: x)
        if index != -1:
            return index
        return self.binarySearch(target, mountain_arr, peak + 1, arrLen - 1, lambda x: -x)