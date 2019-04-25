class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    res = True

    def IsBalanced_Solution(self, pRoot):
        # write code here
        self.isBalancedHelper(pRoot)
        return self.res

    def isBalancedHelper(self, root):
        if not root:
            return 0
        if not self.res:
            return 1
        left = 1 + self.isBalancedHelper(root.left)
        right = 1 + self.isBalancedHelper(root.right)
        if abs(left - right) > 1:
            self.res = False
        return max(left, right)
