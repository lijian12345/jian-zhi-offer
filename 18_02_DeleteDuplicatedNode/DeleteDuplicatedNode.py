class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteDuplication(self, pHead):
        if pHead is None or pHead.next is None:
            return pHead
        q = pHead.next
        if q.val != pHead.val:
            pHead.next = self.deleteDuplication(pHead.next)
        else:
            while pHead.val == q.val and q.next is not None:
                q = q.next
            if q.val != pHead.val:
                pHead = self.deleteDuplication(q)
            else:
                return None
        return pHead
