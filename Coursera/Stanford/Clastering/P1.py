#/usr/bin/env python3
from UnionFind import UnionFind
import os
UF = UnionFind()
PATH = os.getcwd() + "/problemOne.txt"
LENGTH = 500
data = open(PATH, 'r')


def P1():
