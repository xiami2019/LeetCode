# 使用二分查找
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            temp = nums1
            nums1 = nums2
            nums2 = temp
        
        m = len(nums1)
        n = len(nums2)

        totalLeft = m + (n - m + 1) // 2
        left = 0
        right = m

        while left < right:
            i = left + (right - left + 1) // 2
            j = totalLeft - i
            if nums1[i - 1] > nums2[j]:
                right = i - 1
            else:
                left = i

        i = left
        j = totalLeft - i
        nums1LeftMax = float('-inf') if i == 0 else nums1[i - 1]
        nums1RightMin = float('inf') if i == m else nums1[i]
        nums2LeftMax = float('-inf') if j == 0 else nums2[j - 1]
        nums2RightMin = float('inf') if j == n else nums2[j]

        if (m + n) % 2 == 1:
            return max(nums1LeftMax, nums2LeftMax)
        else:
            return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2