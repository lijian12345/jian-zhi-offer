class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        if not numbers:
            return ''
        tmp = sorted(
            numbers,
            cmp=lambda x, y: int(str(x) + str(y)) - int(str(y) + str(x)))
        return ''.join([str(x) for x in tmp])
