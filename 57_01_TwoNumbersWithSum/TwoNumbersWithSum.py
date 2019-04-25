class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # write code here
        res = []
        i, j = 0, len(array) - 1
        while i < j:
            s = array[i] + array[j]
            if s < tsum:
                i += 1
            elif s > tsum:
                j -= 1
            else:
                res.append(array[i])
                res.append(array[j])
                break
        return res
