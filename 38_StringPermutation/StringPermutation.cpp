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
    vector<string> v;
    vector<string> Permutation(string str)
    {
        if (str.size() == 0)
            return v;
        Permutation(str, 0);
        sort(v.begin(), v.end());
        return v;
    }
    void Permutation(string str, int begin)
    {
        if (begin == str.size())
        {
            v.push_back(str);
            return;
        }
        for (int i = begin; i < str.size(); i++)
        {
            if (i != begin && str[i] == str[begin])
            {
                continue;
            }
            swap(str[begin], str[i]);
            Permutation(str, begin + 1);
            swap(str[begin], str[i]);
        }
    }
};