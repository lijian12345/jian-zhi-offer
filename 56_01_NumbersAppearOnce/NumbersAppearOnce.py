class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if len(array) < 2:
            return array
        xor = reduce(lambda x, y: x ^ y, array)
        if xor != 1:
            xor = xor & (~xor + 1)
        res1 = 0
        res2 = 0
        for i in array:
            if i & xor:
                res1 ^= i
            else:
                res2 ^= i
        return [res1, res2]
