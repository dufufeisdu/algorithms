class Solution:
    def corpFlightBookings(self, bookings, n):
        if len(bookings) == 0:
            return []
        bookings.sort(key=lambda x: x[1])
        res = [0] * (bookings[-1][1] + 1)
        for [i, j, k] in bookings:
            for l in range(i, j + 1):
                res[l] += k
        return res[:1]


print(Solution().corpFlightBookings())
