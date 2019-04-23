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
    int GetNumberOfK(vector<int> data, int k)
    {
        int start = 0, end = data.size() - 1;
        int lower = getLower(data, start, end, k);
        int upper = getUpper(data, start, end, k);
        return upper - lower + 1;
    }

    int getLower(vector<int> data, int start, int end, int k)
    {
        int mid = (start + end) >> 1;
        while (start <= end)
        {
            if (data[mid] < k)
                start = mid + 1;
            else
                end = mid - 1;
            mid = (start + end) / 2;
        }
        return start;
    }

    int getUpper(vector<int> data, int start, int end, int k)
    {
        int mid = (start + end) >> 1;
        while (start <= end)
        {
            if (data[mid] <= k)
                start = mid + 1;
            else
                end = mid - 1;
            mid = (start + end) / 2;
        }
        return end;
    }
};

int main()
{
    vector<int> v{1, 2, 3, 3, 3, 3, 4, 5};
    Solution s = Solution();
    cout << s.GetNumberOfK(v, 3);
}