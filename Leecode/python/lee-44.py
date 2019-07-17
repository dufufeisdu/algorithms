class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def remove_double_connected_star(s):
            s = list(s)
            i = 1
            j = 0
            while i < len(s):
                if s[i] != "*" or s[i - 1] != "*":
                    j += 1
                    s[j] = s[i]
                i += 1
            return "".join(s[: j + 1])

        def m_wild(s, p):
            if not p:
                return not s
            if not s:
                return p == "*"
            if p[0] not in "*?":
                if p[0] != s[0]:
                    return False
                else:
                    return m_wild(s[1:], p[1:])
            else:
                if p[0] == "?":
                    return m_wild(s[1:], p[1:])
                else:
                    j = 0
                    while j <= len(s):
                        r = m_wild(s[j:], p[1:])
                        if r:
                            return r
                        j += 1
                    return False

        p = remove_double_connected_star(p)
        print(p)
        return m_wild(s, p)


print(
    Solution().isMatch(
        "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb",
        "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a",
    )
)

