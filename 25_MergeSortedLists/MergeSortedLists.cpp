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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1)
            return pHead2;
        else if (!pHead2)
            return pHead1;
        ListNode *mergedHead = nullptr;
        if (pHead1->val < pHead2->val)
        {
            mergedHead = pHead1;
            mergedHead->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            mergedHead = pHead2;
            mergedHead->next = Merge(pHead1, pHead2->next);
        }
        return mergedHead;
    }
};