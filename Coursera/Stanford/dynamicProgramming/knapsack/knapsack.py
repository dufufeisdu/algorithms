#/usr/bin/env python3
"""This file describes a knapsack instance, and it has the following format:
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]
For example, the third line of the file is "50074 659", indicating that the
second item has value 50074 and size 659, respectively.
You can assume that all numbers are positive. You should assume that item
weights and the knapsack capacity are integers.
In the box below, type in the value of the optimal solution"""


def knapsack():
    data = []
    with open("knapsack1.txt") as f:
        for line in f:
            data.append(map(lambda x: int(x), line.split(" ")))
    total_items = data[0][1]
    max_weight = data[0][0]
    result_table = [[0] * total_items for m in xrange(0, max_weight + 1)]
    for size in xrange(1, total_items + 1):
        current_weight = data[size][1]
        current_value = data[size][0]
        for weight in xrange(current_weight, max_weight):
            result_table[size][weight] = max(
                result_table[size - 1][weight], result_table[size][weight - current_weight] + current_value)
    return {'optimal value': result_table[total_items][max_weight]}


if __name__ == '__main__':
    print(knapsack())
