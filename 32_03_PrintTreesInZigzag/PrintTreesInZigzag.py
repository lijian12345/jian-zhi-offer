from collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def reConstructBinaryTree(pre, lin):
    if not pre and not lin:
        return None
    root = TreeNode(pre[0])
    if set(pre) != set(lin):
        return None
    i = lin.index(pre[0])
    root.left = reConstructBinaryTree(pre[1:i + 1], lin[:i])
    root.right = reConstructBinaryTree(pre[i + 1:], lin[i + 1:])
    return root


class Solution:
    def Print(self, pRoot):
        # write code here
        if not pRoot:
            return []

        res, tmp = [], []
        last = pRoot
        q = deque([pRoot])
        left_to_right = True
        while q:
            t = q.popleft()
            tmp.append(t.val)
            if t.left:
                q.append(t.left)
            if t.right:
                q.append(t.right)
            if t == last:
                res.append(tmp if left_to_right else tmp[::-1])
                left_to_right = not left_to_right
                tmp = []
                if q:
                    last = q[-1]
        return res


t = reConstructBinaryTree([1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15],
                          [8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15])
s = Solution()
print(s.Print(t))