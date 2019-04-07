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
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> st;
        int id = 0;
        for (int i = 0; i < popV.size(); i++)
        {
            while (st.empty() || st.top() != popV[i])
            {
                st.push(pushV[id++]);
                if (id > pushV.size())
                    return false;
            }
            st.pop();
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> p{1, 2, 3, 4, 5};
    vector<int> q{4, 3, 5, 1, 2};
    bool flag = s.IsPopOrder(p, q);
    return 0;
}