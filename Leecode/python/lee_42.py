class Solution:
    def trap(self, height):
        left_max = []
        right_max = []
        l = 0
        r = 0
        for h in height:
            if h > l:
                left_max.append(h)
                l = h
            else:
                left_max.append(l)

        for h in height[::-1]:
            if h > r:
                right_max.append(h)
                r = h
            else:
                right_max.append(r)

        right_max = right_max[::-1]
        print(left_max)
        print(right_max)
        n = len(height)
        i = 0
        water = 0
        while i < n:
            if left_max[i] > right_max[i]:
                w = right_max[i] - height[i]
                if w > 0:
                    water += w
            else:
                w = left_max[i] - height[i]
                if w > 0:
                    water += w
            i += 1
        return water


print(Solution().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))

