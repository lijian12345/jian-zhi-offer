class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def PrintFromTopToBottom(self, root):
        L = []
        if not root:
            return L
        queue = [root]
        while queue:
            root = queue.pop(0)
            L.append(root.val)
            if root.left:
                queue.append(root.left)
            if root.right:
                queue.append(root.right)
        return L


t1 = TreeNode(8)
t2 = TreeNode(6)
t3 = TreeNode(10)
t1.left = t2
t1.right = t3
s = Solution()
print(s.PrintFromTopToBottom(t1))
