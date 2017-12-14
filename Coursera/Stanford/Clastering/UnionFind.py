"""UnionFind.py
Union-find data structure.
"""


class UnionFind:
    """An array[0,1..n] will stand for all the vetices,
    then use the union and find data structure"""

    def __init__(self, totalVetices):
        self.vetices = list(xrange(0, totalVetices))

    def find(self, num):
        while self.vetices[num] != num:
            temp = num
            num = self.vetices[num]
            # path compress
            self.vetices[temp] = self.vetices[num]
        return num

    def union(self, num1, num2):
        p1 = self.find(num1)
        p2 = self.find(num2)
        if p1 != p2:
            self.vetices[p2] = self.vetices[p1]
            return True
        return False
