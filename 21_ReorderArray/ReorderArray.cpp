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

//two pointers
class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        int i = 0, j = array.size() - 1;
        while (i < j)
        {
            while (array[i] % 2 == 1)
                i++;
            while (array[j] % 2 == 0)
                j--;
            if (i < j)
                swap(array[i], array[j]);
        }
    }
};

//稳定解法
class Solution1
{
  public:
    void reOrderArray(vector<int> &array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                    swap(array[j], array[j - 1]);
            }
        }
    }
};