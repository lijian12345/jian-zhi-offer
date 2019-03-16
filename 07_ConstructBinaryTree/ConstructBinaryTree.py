class TreeNode(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


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


def printPre(root):
    if root:
        print("%d " % root.val, end="")
        printPre(root.left)
        printPre(root.right)


def printIn(root):
    if root:
        printIn(root.left)
        print("%d " % root.val, end="")
        printIn(root.right)


def printPost(root):
    if root:
        printPost(root.left)
        printPost(root.right)
        print("%d " % root.val, end="")


pre = [1, 2, 4, 7, 3, 5, 6, 8]
lin = [4, 7, 2, 1, 5, 3, 8, 6]
root = reConstructBinaryTree(pre, lin)
printPre(root)
print()
printIn(root)
print()
printPost(root)
