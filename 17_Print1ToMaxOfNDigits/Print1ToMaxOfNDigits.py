import operator


class Solution(object):
    def Print1ToMaxOfNDigits(self, n):
        if n <= 0:
            return
        number = ['0'] * n
        for i in range(10):
            number[0] = str(i)
            self.__Print1ToMaxOfNDigitsRecursively(number, n, 0)

    def __PrintNumber(self, number):
        if (operator.eq(number, ['0'] * len(number))):
            return
        isBeginning0 = True
        nLength = len(number)

        for i in range(nLength):
            if isBeginning0 and number[i] != '0':
                isBeginning0 = False
            if not isBeginning0:
                print('%c' % number[i], end='')
        print('\t', end='')

    def __Print1ToMaxOfNDigitsRecursively(self, number, length, index):
        if index == length - 1:
            self.__PrintNumber(number)
            return
        for i in range(10):
            number[index + 1] = str(i)
            self.__Print1ToMaxOfNDigitsRecursively(number, length, index + 1)


solution = Solution()
solution.Print1ToMaxOfNDigits(4)
