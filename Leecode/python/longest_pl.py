class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2:
            return s
        if len(s) == 2 and s[0] == s[1]:
            return s
        if len(s) == 2 and s[0] != s[1]:
            return s[0]

        max_sub = s[0]
        for idx in range(0, len(s) - 1):
            i = idx
            j = idx + 1
            while i >= 0 and j < len(s):
                if s[i] != s[j]:
                    break
                i -= 1
                j += 1
            i += 1
            j -= 1
            if j - i + 1 > len(max_sub):
                max_sub = s[i : j + 1]
        for idx in range(1, len(s) - 1):
            i = idx - 1
            j = idx + 1
            while i >= 0 and j <= len(s) - 1:
                if s[i] != s[j]:
                    break
                i -= 1
                j += 1
            i += 1
            j -= 1
            if j - i + 1 > len(max_sub):
                max_sub = s[i : j + 1]
        return max_sub


print(Solution().longestPalindrome("cvva"))

