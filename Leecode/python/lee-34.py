class Solution:
    def searchRange(self, nums, target):
        res = [-1, -1]
        l = len(nums)
        s = 0
        e = l
        while s < e:
            m = (s + e - 1) // 2
            if nums[m] == target:
                ls = m
                rate = 1
                while True:
                    if ls >= 0 and nums[ls] == target:
                        if ls == 0:
                            res[0] = 0
                            break
                        if nums[ls - 1] != target:
                            res[0] = ls
                            break
                        else:
                            ls -= rate
                            rate *= 2
                    else:
                        ls += rate // 2
                        rate = 1
                rs = m
                rate = 1
                while True:
                    if rs < l and nums[rs] == target:
                        if rs == l - 1:
                            res[1] = l - 1
                            break
                        if nums[rs + 1] != target:
                            res[1] = rs
                            break
                        else:
                            rs += rate
                            rate *= 2
                    else:
                        rs -= rate // 2
                        rate = 1
                break
            elif nums[m] < target:
                s = m + 1
            else:
                e = m

        return res


print(
    Solution().searchRange(
        [0, 0, 0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 8, 8, 9, 9, 10, 10, 11, 11], 0
    )
)

