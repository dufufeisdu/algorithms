class Solution:
    def longestValidParentheses(self, s: str) -> int:
        #         stk:
        # longest = 0
        # stk = [-1]
        # for idx,c in enumerate(s):
        #     if c=='(':
        #         stk.append(idx)
        #     else:
        #         if len(stk)==1:
        #             stk.pop()
        #             stk.append(idx)
        #         else:
        #             stk.pop()
        #             longest = max(idx-stk[-1],longest)
        #         DP
        l = len(s)
        dp = [0] * (l + 2)
        for idx in range(1, l):
            if s[idx] == ")":
                if s[idx - 1] == "(":
                    dp[idx] = dp[idx - 2] + 2
                else:
                    if idx - dp[idx - 1] - 1 >= 0 and s[idx - dp[idx - 1] - 1] == "(":

                        dp[idx] = dp[idx - 1] + dp[idx - dp[idx - 1] - 2] + 2
                print(dp)
        return max(dp)


print(Solution().longestValidParentheses("(()))())(("))
