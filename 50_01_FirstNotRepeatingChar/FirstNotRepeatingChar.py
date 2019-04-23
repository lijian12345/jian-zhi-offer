class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        if len(s) <= 0:
            return -1

        D = {}
        for i in s:
            D[i] = D.get(i, 0) + 1
        for i, v in D.items():
            if v == 1:
                return s.index(i)


s = Solution()
print(s.FirstNotRepeatingChar("google"))
