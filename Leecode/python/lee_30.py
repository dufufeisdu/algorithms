class Solution:
    def findSubstring(self, s, words):
        if len(words) == 0:
            return
        dic = {}
        count = 0
        for word in words:
            if word in dic:
                dic[word] += 1
            else:
                dic[word] = 1
            count += 1

        n = len(words[0])
        res = []
        for idx in range(len(s)):
            i = idx
            d = dic.copy()
            a = s[idx : idx + n]
            while i < len(s) and a in d:
                if d[a] > 0:
                    d[a] -= 1
                    i += n
                else:
                    break
            if i == idx + n * count:
                res.append(idx)
        return res


print(Solution().findSubstring("barfoothefoobarman", ["foo", "bar"]))

