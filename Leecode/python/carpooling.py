def carPooling(trips, capacity):
    trips.sort(key=lambda a: a[1])
    print(trips)
    for idx, [start, end, cap] in enumerate(trips):
        init_cap = cap
        for [s, e, c] in trips[:idx]:
            if start >= s and start < e:
                init_cap += c
                if init_cap > capacity:
                    return False
    return True


print(carPooling([[9, 3, 4], [9, 1, 7], [4, 2, 4], [7, 4, 5]], 23))
