class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head is None or k == 0:
            return None
        pAhead = head
        for i in range(k - 1):
            if pAhead.next is not None:
                pAhead = pAhead.next
            else:
                return None
        pBehind = head
        while pAhead.next is not None:
            pAhead = pAhead.next
            pBehind = pBehind.next
        return pBehind
