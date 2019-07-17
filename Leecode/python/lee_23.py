# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def ls_to_LN(ls):
    root = ListNode(0)
    x = root
    for val in ls:
        x.next = ListNode(val)
        x = x.next
    return root.next


def ln_to_ls(ln):
    x = ln
    ls = []
    while x and x.val is not None:
        ls.append(x.val)
        x = x.next
    return ls


class Solution:
    def mergeKLists(self, lists):
        root = ListNode(0)
        if not len(lists):
            return root.next
        if len(lists) == 1:
            return lists[0]
        x = root
        while len(lists) > 1:
            max_val = lists[0]
            i = 0
            for idx, ln in enumerate(lists):
                if max_val.val > ln.val:
                    max_val = ln
                    i = idx
            x.next = max_val
            x = x.next
            max_val = max_val.next
            if not max_val:
                del lists[i]
            else:
                lists[i] = max_val
        x.next = lists[0]
        return root.next


print(
    ln_to_ls(
        Solution().mergeKLists(
            [ls_to_LN([1, 4, 5]), ls_to_LN([1, 3, 4]), ls_to_LN([2, 6])]
        )
    )
)

