class Solution:
    def search(self, nums, target) -> int:
        s = 0
        e = len(nums) - 1
        while s < e:
            m = (s + e) // 2
            print(nums[m])
            if nums[m] == target:
                return m
            if nums[m]<nums[s]:
                if target<nums[s]:
                    e = m-1
                else:
                    if target<
            else:
                if target<nums[m] and nums[s]<target:


        return -1


print(Solution().search([4, 5, 6, 7, 0, 1, 2], 0))

