class Solution:
    def rec(self, n1, n2, k):
        m = len(n1)
        n = len(n2)
        if len(n2) < len(n1):
            return self.rec(n2, n1, k)
        if len(n1) == 0:
            return n2[k]
        if k == 0:
            return min(n1[0], n2[0])
        if n1[k // 2] < n2[k // 2]:
            if m < k // 2:
                return n2[k // 2 - m]
            else:
                return self.rec(n1[k // 2 :], n2, k // 2)
        elif n1[k // 2] > n2[k // 2]:
            return self.rec(n1, n2[k // 2 :], k // 2)
        else:
            return n1[k // 2]

    def findMedianSortedArrays(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)
        if m + n & 0x1:
            return 1.0 * self.rec(nums1, nums2, (m + n - 1) // 2)
        else:
            return 0.5 * (
                self.rec(nums1, nums2, (m + n) // 2)
                + self.rec(nums1, nums2, (m + n - 1) // 2)
            )


s = Solution()
print(s.findMedianSortedArrays([1, 2], [3, 4]))

