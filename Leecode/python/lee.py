def carPooling(trips,capacity):
    trips.sort(key=lambda a:a[1])
    print(trips)
    i = 0
    while i<len(trips):
        init_cap = trips[i][0]
        start = trips[i][1]
        end = trips[i][2]
        j = 1
        while j<len(trips):
            c = trips[j][0]
            s = trips[j][1]
            if end>s:
                init_cap+=c
            else:
                break
            if init_cap>capacity:
                return False
            j+=1
        i+=1
    return True

print(carPooling([[3,2,7],[3,7,9],[8,3,9]],11)
