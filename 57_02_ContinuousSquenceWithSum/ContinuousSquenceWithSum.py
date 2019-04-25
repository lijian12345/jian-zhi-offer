class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        i, j = 1, 2
        s = i + j
        res = []
        middle = (tsum + 1) >> 1
        while i < middle:
            if s > tsum:
                s -= i
                i += 1
            elif s < tsum:
                j += 1
                s += j
            else:
                t = []
                for k in range(i, j + 1):
                    t.append(k)
                res.append(t)
                j += 1
                s += j
        return res
