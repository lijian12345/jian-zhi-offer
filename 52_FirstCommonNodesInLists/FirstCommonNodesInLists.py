class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        p = pHead1
        q = pHead2
        while p != q:
            p = pHead2 if p is None else p.next
            q = pHead1 if q is None else q.next
        return p
