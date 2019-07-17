class Solution:
    def combinationSum(self, candidates, target):
        candidates.sort(reverse=True)
        res = []

        def comb(candidates, target, candy):
            if target == 0:
                res.append(candy)
                return
            if target < 0:
                return
            n = len(candidates)
            idx = 0
            while idx < n:
                comb(candidates, target - candidates[0], [candidates[0]] + candy)
                candidates = candidates[1:]
                idx += 1

        comb(candidates, target, [])
        return res


print(Solution().combinationSum([2, 3, 6, 7], 7))
