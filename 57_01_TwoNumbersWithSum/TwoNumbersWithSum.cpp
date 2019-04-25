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
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> res;
        int i = 0, j = array.size() - 1;
        // int product = 1e9;
        while (i < j)
        {
            int s = array[i] + array[j];
            if (s == sum)
            {
                // if (array[i] * array[j] < product)
                // {
                // product = array[i] * array[j];
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
                // }
            }
            else if (s < sum)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};