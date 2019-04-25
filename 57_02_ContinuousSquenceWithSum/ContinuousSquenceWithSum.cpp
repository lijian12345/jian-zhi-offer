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
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        int i = 1, j = 2;
        int s = i + j;
        int middle = (sum + 1) >> 1;
        vector<vector<int>> v;
        while (i < middle)
        {
            if (s > sum)
            {
                s -= (i++);
            }
            else if (s < sum)
            {
                s += (++j);
            }
            else
            {
                vector<int> t;
                for (int k = i; k <= j; ++k)
                {
                    t.push_back(k);
                }
                v.push_back(t);
                s += (++j);
            }
        }
        return v;
    }
};

int main()
{
    Solution s = Solution();
    auto res = s.FindContinuousSequence(9);
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}