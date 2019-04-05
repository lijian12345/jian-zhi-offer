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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == nullptr || k == 0)
            return nullptr;
        ListNode *pAhead = pListHead;
        for (unsigned int i = 0; i < k - 1; i++)
        {
            if (pAhead->next)
                pAhead = pAhead->next;
            else
                return nullptr;
        }
        ListNode *pBehind = pListHead;
        while (pAhead->next)
        {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pBehind;
    }
};