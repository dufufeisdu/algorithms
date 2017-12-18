#/usr/bin/env python3
# output:Indexs of element in the max weight independent set
# dynamic programming


def max_weight_independent_set():
    weights = []
    with open("mwis.txt") as f:
        for line in f:
            weights.append([int(line), [1]])
    vertice_number = weights[0][0]
    weights[0] = [0, [0]]
    for i in xrange(3, vertice_number + 1):
        if weights[i][0] + weights[i - 2][0] > weights[i][0] + weights[i - 3][0]:
            weights[i][1] = list(weights[i - 2][1])
            weights[i][1].append(i)
            weights[i][0] = weights[i][0] + weights[i - 2][0]

        else:
            weights[i][1] = list(weights[i - 3][1])
            weights[i][1].append(i)
            weights[i][0] = weights[i][0] + weights[i - 3][0]

    result = weights[-2:]
    return result[0][1] if result[0][0] > result[1][0] else result[1][1]


if __name__ == "__main__":

    index_set = max_weight_independent_set()
    test = [1, 2, 3, 4, 17, 117, 517, 997]
    string = ''
    for i in test:
        if i in index_set:
            string += '1'
        else:
            string += '0'
    print("The code is:", string)
