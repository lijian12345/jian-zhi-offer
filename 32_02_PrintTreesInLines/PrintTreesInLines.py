class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def PrintInLines(self, root):
        if not root:
            return
        queue = [root]
        nextLevel = 0
        toBePrinted = 1
        while queue:
            root = queue.pop(0)
            print("%d " % root.val, end='')
            if root.left:
                queue.append(root.left)
                nextLevel += 1
            if root.right:
                queue.append(root.right)
                nextLevel += 1
            toBePrinted -= 1
            if toBePrinted == 0:
                print()
                toBePrinted = nextLevel
                nextLevel = 0


t1 = TreeNode(8)
t2 = TreeNode(6)
t3 = TreeNode(10)
t1.left = t2
t1.right = t3
s = Solution()
print(s.PrintInLines(t1))
