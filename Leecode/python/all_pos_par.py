class Solution:
    def generateParenthesis(self, n):
        if n == 0:
            return [""]
        if n == 1:
            return ["()"]
        res = {}
        for ps in self.generateParenthesis(n - 1):
            res["(" + ps + ")"] = True
            res["()" + ps] = True
            res[ps + "()"] = True
        return res.keys()


print(Solution().generateParenthesis(4))
