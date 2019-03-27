#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
using namespace std;

bool g_InvalidInput = false;

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1 == 1)
        result *= base;
    return result;
}

double Power(double base, int exponent)
{
    g_InvalidInput = false;
    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);
    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;
    return result;
}
