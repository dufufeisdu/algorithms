#/usr/bin/env python3
from UnionFind import UnionFind
import os

PATH = os.getcwd() + "/ProblemOne.txt"


def p1(k=4, length=500):
    '''This file describes a distance function (equivalently,
    a complete graph with edge costs). It has the following format:
    [number_of_nodes]
    [edge 1 node 1] [edge 1 node 2] [edge 1 cost]
    [edge 2 node 1] [edge 2 node 2] [edge 2 cost]

    There is one edge (i,j) for each choice of 1<i<j<n,
    where n is the number of nodes.
    For example, the third line of the file is "1 3 5250",
    indicating that the distance between nodes 1 and 3
    (equivalently, the cost of the edge (1,3)) is 5250.
    You can assume that distances are positive,
    but you should NOT assume that they are distinct.
    Your task in this problem is to run the clustering
    algorithm from lecture on this data set, where the
    target number k of clusters is set to 4. What is
    the maximum spacing of a 4-clustering?
        '''
    count = length - k
    # Read data
    with open(PATH) as f:
        data = []
        for line in f:
            line = line.split(" ")
            data.append((int(line[2]), int(line[0]), int(line[1])))
    # sort
    data.sort()
    # Init a unionFind data structure
    uf = UnionFind(length + 1)
    # Caculate 4-claster
    for d in data:
        if count > 0:
            if uf.union(d[1], d[2]):
                count -= 1
        else:
            # print(uf.vetices)
            # for i in xrange(1, length + 1):
            #     print(uf.find(i))
            break
    # Finding the spacing
    first_flag = True
    spacing = 0
    for d in data:
        if first_flag:
            if uf.find(d[1]) != uf.find(d[2]):
                first_flag = False
                spacing = d[0]
        else:
            if uf.find(d[1]) != uf.find(d[2]):
                spacing = spacing if spacing < d[0] else d[0]

    return spacing


if __name__ == "__main__":
    # ???why it called max-spaing, I think it should be min-spacing?
    print("Max-spacing:", p1())
