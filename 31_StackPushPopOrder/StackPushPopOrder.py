class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        stack = []
        id = 0
        for i in popV:
            while not stack or stack[-1] != i:
                if id == len(pushV):
                    break
                stack.append(pushV[id])
                id += 1
            if stack[-1] != i:
                break
            stack.pop()
        if not stack:
            return True
        else:
            return False


s = Solution()
print(s.IsPopOrder([1, 2, 3, 4, 5], [4, 3, 5, 1, 2]))
