class Solution:
    def longestWPI(self, hours):
        li = 0
        i = 0
        iv = 0
        for h in hours:
            iv += 1
            if h > 8:
                i += 1
            else:
                i -= 1
                if i < 0:
                    i = 0
                    iv = 0
            li = max(li, iv)
        i = 0
        iv = 0
        for h in hours[::-1]:
            iv += 1
            if h > 8:
                i += 1
            else:
                i -= 1
                if i < 0:
                    i = 0
                    iv = 0
            li = max(li, iv)

        return li


print(Solution().longestWPI([9, 9, 9, 6, 6, 6, 9]))

