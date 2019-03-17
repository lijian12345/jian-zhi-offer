class Solution:
    def jumpFloor(self, number):
        res = [0, 1, 2]
        if number < 3:
            return res[number]
        a, b, fib = 1, 2, 0
        for i in range(3, number + 1):
            fib = a + b
            a, b = b, fib
        return fib
