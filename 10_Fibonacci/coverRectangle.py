class Solution:
    def rectCover(self, number):
        if number == 0:
            return 0
        if number == 1:
            return 1
        if number == 2:
            return 2
        a, b = 1, 2
        number -= 2
        while number > 0:
            a, b = b, a + b
            number -= 1
        return b
