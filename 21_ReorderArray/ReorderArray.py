class Solution:
    def reOrderArray(self, array):
        # write code here
        return sorted(array, key=lambda c: c % 2, reverse=True)


s = Solution()
print(s.reOrderArray([1, 2, 3, 4, 5, 6, 7]))
