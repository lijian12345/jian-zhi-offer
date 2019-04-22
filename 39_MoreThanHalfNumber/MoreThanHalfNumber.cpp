#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size() == 0)
            return 0;
        int low = 0;
        int high = numbers.size() - 1;
        int middle = numbers.size() >> 1;
        int index = partition(numbers, low, high);
        while (index != middle)
        {
            if (index > middle)
                high = index - 1;
            else
                low = index + 1;
            index = partition(numbers, low, high);
        }
        int res = numbers[index];
        if (!checkMoreThanHalf(numbers, res))
            return 0;
        return res;
    }

    bool checkMoreThanHalf(vector<int> numbers, int res)
    {
        int times = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == res)
                times++;
        }
        if (times * 2 <= numbers.size())
            return false;
        else
            return true;
    }

    int partition(vector<int> numbers, int low, int high)
    {
        if (low < high)
        {
            int pivot = numbers[low];
            while (low < high)
            {
                while (low < high && numbers[high] >= pivot)
                    --high;
                numbers[low] = numbers[high];
                while (low < high && numbers[low] <= pivot)
                    ++low;
                numbers[high] = numbers[low];
            }
            numbers[low] = pivot;
        }
        return low;
    }
};

class Solution1
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size() == 0)
            return 0;
        int res = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (times == 0)
            {
                res = numbers[i];
                times = 1;
            }
            else if (numbers[i] == res)
                times++;
            else
                times--;
        }
        if (!checkMoreThanHalf(numbers, res))
            return 0;
        return res;
    }

    bool checkMoreThanHalf(vector<int> numbers, int res)
    {
        int times = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == res)
                times++;
        }
        if (times * 2 <= numbers.size())
            return false;
        else
            return true;
    }
};