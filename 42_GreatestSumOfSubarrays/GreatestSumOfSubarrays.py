class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        curSum, maxSum = 0, -float('inf')
        for i in array:
            curSum += i
            if curSum > maxSum:
                maxSum = curSum
            if curSum < 0:
                curSum = 0
        return maxSum
