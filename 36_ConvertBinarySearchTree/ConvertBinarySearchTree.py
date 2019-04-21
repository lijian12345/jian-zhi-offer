class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.pre = None

    def Convert(self, pRootOfTree):
        # write code here
        if not pRootOfTree:
            return None
        self.CovertNode(pRootOfTree, self.pre)
        res = pRootOfTree
        while res.left:
            res = res.left
        return res

    def CovertNode(self, cur, pre):
        if not cur:
            return
        self.CovertNode(cur.left, self.pre)
        cur.left = self.pre
        if self.pre:
            self.pre.right = cur
        self.pre = cur
        self.CovertNode(cur.right, self.pre)
