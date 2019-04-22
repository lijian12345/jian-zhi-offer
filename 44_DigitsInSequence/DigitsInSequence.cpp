#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n < 0)
            return -1;
        int digits = 1;
        while (true)
        {
            int numbers = countOfIntegers(digits);
            if (n < numbers * digits)
                return digitAtIndex(n, digits);
            n -= digits * numbers;
            digits++;
        }
        return -1;
    }

    int countOfIntegers(int digits)
    {
        if (digits == 1)
            return 10;
        int count = pow(10, digits - 1);
        return 9 * count;
    }

    int digitAtIndex(int index, int digits)
    {
        int number = beginNumber(digits) + index / digits;
        int indexFromRight = digits - index % digits;
        for (int i = 1; i < indexFromRight; ++i)
            number /= 10;
        return number % 10;
    }

    int beginNumber(int digits)
    {
        if (digits == 1)
            return 0;
        return pow(10, digits);
    }
};
