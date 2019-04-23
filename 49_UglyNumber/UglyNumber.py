class Solution:
    def GetUglyNumber_Solution(self, index):
        # write code here
        if index <= 0:
            return 0
        res = [1]
        i = 1
        t2, t3, t5 = 0, 0, 0
        while i < index:
            res.append(min(res[t2] * 2, res[t3] * 3, res[t5] * 5))
            if res[-1] == res[t2] * 2:
                t2 += 1
            if res[-1] == res[t3] * 3:
                t3 += 1
            if res[-1] == res[t5] * 5:
                t5 += 1
            i += 1
        return res[-1]


s = Solution()
print(s.GetUglyNumber_Solution(6))
