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
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        return bst(sequence, 0, sequence.size() - 1);
    }
    bool bst(vector<int> sequence, int begin, int end)
    {
        if (sequence.empty() || begin > end)
            return false;
        int root = sequence[end];
        int i = begin;
        for (; i < end; ++i)
            if (sequence[i] > root)
                break;
        int j = i;
        for (; j < end; ++j)
            if (sequence[j] < root)
                return false;
        bool left = true;
        if (i > begin)
            left = bst(sequence, begin, i - 1);
        bool right = true;
        if (i < end - 1)
            right = bst(sequence, i, end - 1);
        return left && right;
    }
};