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
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        if not root:
            return []
        if root.val == expectNumber and not root.left and not root.right:
            return [[root.val]]
        result = []
        left = self.FindPath(root.left, expectNumber - root.val)
        right = self.FindPath(root.right, expectNumber - root.val)
        for i in left + right:
            result.append([root.val] + i)
        return result


t = reConstructBinaryTree([10, 5, 4, 7, 12], [4, 5, 7, 10, 12])
s = Solution()
print(s.FindPath(t, 22))
