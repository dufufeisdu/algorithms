class Solution:
    def combinationSum(self, candidates, target):
        candidates.sort()

        def comb(candidates, target):
            if target == 0 and len(candidates) != 0:
                return [[]]

            if len(candidates) == 0 or target < candidates[0]:
                return []

            res = []
            while len(candidates) > 0:
                t = target
                while target > 0:
                    target -= candidates[-1]
                    ls = comb(candidates[:], target)
                    if len(ls) > 0:
                        ls = [a + [candidates[-1]] for a in ls]
                        res = res + ls
                target = t
                candidates.pop()
            return res

        return comb(candidates, target)


print(Solution().combinationSum([2], 4))

