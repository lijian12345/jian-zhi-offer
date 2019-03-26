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

int NumberOf1(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = (n - 1) & n;
    }
    return count;
}
