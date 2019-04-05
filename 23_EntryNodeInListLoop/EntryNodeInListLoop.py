class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        meetingNode = self.MeetingNode(pHead)
        if meetingNode is None:
            return None
        count = 1
        metNode = meetingNode
        while metNode.next != meetingNode:
            metNode = metNode.next
            count += 1
        pSlow = pHead
        pFast = pHead
        for i in range(count):
            pFast = pFast.next
        while pSlow != pFast:
            pFast = pFast.next
            pSlow = pSlow.next
        return pFast

    def MeetingNode(self, head):
        if head is None:
            return None
        pSlow = head.next
        if pSlow is None:
            return None
        pFast = pSlow.next
        while pFast and pSlow:
            if pFast == pSlow:
                return pFast
            pSlow = pSlow.next
            pFast = pFast.next
            if pFast:
                pFast = pFast.next
        return None
