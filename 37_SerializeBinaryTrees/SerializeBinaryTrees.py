class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def reConstructBinaryTree(lpre, lin):
    if not lpre and not lin:
        return None
    root = TreeNode(lpre[0])
    i = lin.index(lpre[0])
    root.left = reConstructBinaryTree(lpre[1:i + 1], lin[:i])
    root.right = reConstructBinaryTree(lpre[i + 1:], lin[i + 1:])
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


class Solution:
    def __init__(self):
        self.flag = -1

    def Serialize(self, root):
        # write code here
        if not root:
            return '#'
        return str(root.val) + ',' + self.Serialize(
            root.left) + ',' + self.Serialize(root.right)

    def Deserialize(self, s):
        # write code here
        self.flag += 1
        L = s.split(',')
        if self.flag >= len(s):
            return None
        root = None
        if L[self.flag] != '#':
            root = TreeNode(int(L[self.flag]))
            root.left = self.Deserialize(s)
            root.right = self.Deserialize(s)
        return root


pre = [1, 2, 4, 7, 3, 5, 6, 8]
lin = [4, 7, 2, 1, 5, 3, 8, 6]
root = reConstructBinaryTree(pre, lin)
s = Solution()
ss = s.Serialize(root)
print(ss)
sss = s.Deserialize(ss)
printPre(sss)
print()
printIn(sss)
print()
printPost(sss)
