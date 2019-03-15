class ListNode(object):
    def __init__(self, value, next=None):
        self.val = value
        self.next = next


class LinkedList(object):
    def __init__(self):
        self.root = None

    def addNode(self, data):
        if self.root is None:
            self.root = ListNode(data)
            return self.root
        else:
            cursor = self.root
            while cursor.next is not None:
                cursor = cursor.next
            cursor.next = ListNode(data)
            return self.root

    def listPrint(self):
        node = self.root
        while node:
            print(node.val)
            node = node.next


class Solution:
    def printListFromTailToHead(self, listNode):
        if not listNode:
            return []

        result = []
        while listNode:
            result.insert(0, listNode.val)
            listNode = listNode.next
        return result


ll = LinkedList()
for i in range(10):
    ll.addNode(i)
ll.listPrint()
s = Solution()
print(s.printListFromTailToHead(ll.root))
