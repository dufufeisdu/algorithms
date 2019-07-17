def pathInZigZagTree(label):
    res = [label]
    levle = 0
    temp = label
    while label // 2:
        levle += 1
        label = label // 2
    label = temp
    r = 2 ** (levle + 1) - 1
    l = 2 ** (levle)
    mirror = l + r - label
    mirror_res = [mirror]

    while label != 1:
        res.append(label // 2)
        label = label // 2
    print(res)
    while mirror != 1:
        mirror_res.append(mirror // 2)
        mirror = mirror // 2
    print(mirror_res)
    path = []
    for i in range(len(res)):
        if i % 2 == 0:
            path.append(res[i])
        else:
            path.append(mirror_res[i])
    return path[::-1]


print(pathInZigZagTree(14))
