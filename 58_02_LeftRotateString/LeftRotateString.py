class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        return s[n:] + s[:n]
