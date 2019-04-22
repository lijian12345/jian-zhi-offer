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
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int curSum = array[0];
        int maxSum = array[0];
        for (int i = 1; i < array.size(); ++i)
        {
            curSum += array[i];
            if (maxSum < curSum)
                maxSum = curSum;
            if (curSum < 0)
                curSum = 0;
        }
        return maxSum;
    }
};