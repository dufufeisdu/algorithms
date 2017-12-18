#/usr/bin/env python3
class Huffmantree(object):
    def __init__(self, p):
        self.p = p
        self.left = None
        self.right = None
        self.min_depth = 0
        self.max_depth = 0

    def merge(self, tree1, tree2):
        p = tree1.p + tree2.p
        new_tree = Huffmantree(p)
        new_tree.left = tree1 if tree1.p > tree2.p else tree2
        new_tree.right = tree2 if tree1.p > tree2.p else tree1
        new_tree.min_depth = tree1.min_depth + \
            1 if tree1.min_depth < tree2.min_depth else tree2.min_depth + 1
        new_tree.max_depth = tree1.max_depth + \
            1 if tree1.max_depth > tree2.max_depth else tree2.max_depth + 1
        return new_tree
