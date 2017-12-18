#/usr/bin/env python3
from huffmantree import Huffmantree
import heapq


def huffman_code():
    data = []
    with open("huffman.txt") as f:
        for line in f:
            data.append(int(line))
    length = data[0]
    data = data[1:]
    total = sum(data)
    data = map(lambda x: (float(x) / total,
                          Huffmantree(float(x) / total)), data)
    heapq.heapify(data)
    while len(data) > 1:
        tree1 = heapq.heappop(data)[1]
        tree2 = heapq.heappop(data)[1]
        new_tree = tree1.merge(tree1, tree2)
        heapq.heappush(data, (new_tree.p, new_tree))
    return {
        "min_depth": data[0][1].min_depth,
        "max_depth": data[0][1].max_depth
    }


if __name__ == "__main__":
    print(huffman_code())
