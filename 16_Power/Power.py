class Solution(object):
    def Power(self, base, exponent):
        try:
            result = self.power_value(base, abs(exponent))
            if exponent < 0:
                return 1.0 / result
        except ZeroDivisionError:
            print('Error: base is zero')
        else:
            return result

    def power_value(self, base, exponent):
        if exponent == 0:
            return 1
        if exponent == 1:
            return base
        result = self.power_value(base, exponent >> 1)
        result *= result
        if exponent & 0x1 == 1:
            result *= base
        return result
