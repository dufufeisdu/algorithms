import unittest
import os.path
from UnionFind import UnionFind


class Test_UnionFind(unittest.TestCase):
    def setUp(self):
        self.uf = UnionFind(10)

    def test_find(self):
        self.assertEqual(self.uf.find(1), 1)

    def test_union(self):
        self.uf.union(1, 2)

        self.assertEqual(self.uf.find(1), 1)
        self.assertEqual(self.uf.find(2), 1)

        self.uf.union(3, 4)
        self.uf.union(1, 4)

        self.assertEqual(self.uf.find(1), 1)
        self.assertEqual(self.uf.find(2), 1)
        self.assertEqual(self.uf.find(3), 1)
        self.assertEqual(self.uf.find(4), 1)


if __name__ == "__main__":
    unittest.main()
