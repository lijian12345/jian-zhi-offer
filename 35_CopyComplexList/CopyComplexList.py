class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None


def createList(lst):
    head = RandomListNode(lst[0])
    p = head
    for i in lst[1:]:
        tmp = RandomListNode(i)
        p.next = tmp
        p = tmp
    return head


def printList(head):
    while head:
        print(
            "%d " % head.label,
            head.random.label if head.random else None,
            ' ',
            end='')
        head = head.next


class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead):
        # write code here
        if not pHead:
            return
        head = self.copyNode(pHead)
        head = self.setRandom(head)
        cloneHead = self.splitTwo(head)
        return cloneHead

    def copyNode(self, head):
        cur = head
        while cur:
            temp = RandomListNode(cur.label)
            temp.next = cur.next
            cur.next = temp
            cur = temp.next
        return head

    def setRandom(self, head):
        cur = head
        while cur:
            p = cur.next
            if cur.random:
                p.random = cur.random.next
            cur = p.next
        return head

    def splitTwo(self, head):
        cur = head
        cloneHead = None
        cloneCur = None
        if cur:
            cloneHead = cloneCur = cur.next
            cur.next = cloneHead.next
            cur = cur.next
        while cur:
            cloneCur.next = cur.next
            cloneCur = cloneCur.next
            cur.next = cloneCur.next
            cur = cur.next
        return cloneHead


L = createList([1, 2, 3, 4, 5])
cur = L
# A, B, C, D, E = None, None, None, None, None
while cur:
    if cur.label == 1:
        A = cur
    if cur.label == 2:
        B = cur
    if cur.label == 3:
        C = cur
    if cur.label == 4:
        D = cur
    if cur.label == 5:
        E = cur
    cur = cur.next

A.random = C
B.random = E
D.random = B

s = Solution()
# printList(L)
L = s.Clone(L)
# L = s.copyNode(L)
# L = s.setRandom(L)
# L = s.splitTwo(L)
printList(L)
