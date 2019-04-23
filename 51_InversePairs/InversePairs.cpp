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
    int InversePairs(vector<int> data)
    {
        int len = data.size();
        vector<int> copy(len);
        for (int i = 0; i < len; ++i)
            copy[i] = data[i];
        long long count = InversePairsCore(data, copy, 0, len - 1);
        // for (auto i : copy)
        //     cout << i << " ";
        return count % 1000000007;
    }

    long long InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end)
    {
        if (start == end)
        {
            copy[start] = data[start];
            return 0;
        }
        int len = (end - start) / 2;
        long long left = InversePairsCore(copy, data, start, start + len);
        long long right = InversePairsCore(copy, data, start + len + 1, end);
        int i = start + len;
        int j = end;
        int indexCopy = end;
        long long count = 0;
        while (i >= start && j >= start + len + 1)
        {
            if (data[i] > data[j])
            {
                copy[indexCopy--] = data[i--];
                count += j - start - len;
            }
            else
            {
                copy[indexCopy--] = data[j--];
            }
        }
        for (; i >= start; --i)
            copy[indexCopy--] = data[i];
        for (; j >= start + len + 1; --j)
            copy[indexCopy--] = data[j];
        return left + right + count;
    }
};

int main()
{
    vector<int> v{7, 5, 6, 4};
    Solution s = Solution();
    int cut = s.InversePairs(v);
    cout << cut;
}