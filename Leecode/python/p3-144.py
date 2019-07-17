class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        def find_node(tree, value):
            if not tree:
                return None, None
            if tree.val == value:
                return tree.left, tree.right
            if tree.left and tree.left.val == value:
                temp = tree.left
                tree.left = None
                return temp, tree.right
            if tree.right and tree.right.val == value:
                temp = tree.right
                tree.right = None
                return tree.left, temp
            left, right = find_node(tree.left, value)
            return left, right if left and right else find_node(tree.right, value)

        res = [TreeNode]
        for value in to_delete:
            for idx, tree in enumerate(res):
                left, right = find_node(tree, value)
                if left or right:
                    del res[idx]
                    if left:
                        res.append(left)
                    if right:
                        res.append(right)
                    break
        return res

print(Solution().)
