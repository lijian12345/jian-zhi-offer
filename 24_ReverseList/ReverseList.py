class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        reversedHead = None
        p = pHead
        pre = None
        while p:
            q = p.next
            if q is None:
                reversedHead = p
            p.next = pre
            pre = p
            p = q
        return reversedHead
