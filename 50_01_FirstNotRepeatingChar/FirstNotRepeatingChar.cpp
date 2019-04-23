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
    int FirstNotRepeatingChar(string str)
    {
        if (str.empty())
            return -1;
        int cnt[100] = {0};
        int res = -1;
        for (int i = 0; i < str.size(); ++i)
        {
            cnt[str[i] - 'A']++;
        }
        for (int i = 0; i < str.size(); ++i)
        {
            if (cnt[str[i] - 'A'] == 1)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};