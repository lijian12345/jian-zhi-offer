class Solution:
    def __init__(self):
        self.dataStack = []
        self.minStack = []

    def push(self, node):
        # write code here
        self.dataStack.append(node)
        if not self.minStack:
            self.minStack.append(node)
        elif self.minStack[-1] < node:
            self.minStack.append(self.minStack[-1])
        else:
            self.minStack.append(node)

    def pop(self):
        # write code here
        self.dataStack.pop()
        self.minStack.pop()

    def top(self):
        # write code here
        return self.dataStack[-1]

    def min(self):
        # write code here
        return self.minStack[-1]
