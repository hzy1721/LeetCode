class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        L1, R1, L2, R2 = 0, len(nums1)-1, 0, len(nums2)-1
        res1, res2 = 0, 0
        while L1 <= R1 or L2 <= R2:
            if L2 > R2 or (L1 <= R1 and nums1[L1] <= nums2[L2]):
                res1 = nums1[L1]
                L1 += 1
            else:
                res1 = nums2[L2]
                L2 += 1
            if L1 > R1 and L2 > R2:
                break
            if L2 > R2 or (L1 <= R1 and nums1[R1] >= nums2[R2]):
                res2 = nums1[R1]
                R1 -= 1
            else:
                res2 = nums2[R2]
                R2 -= 1
        if (len(nums1)+len(nums2))%2 == 0:
            return (res1 + res2) / 2
        else:
            return res1