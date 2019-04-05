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
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *reversedHead = nullptr;
        ListNode *p = pHead;
        ListNode *pre = nullptr;
        while (p)
        {
            ListNode *q = p->next;
            if (q == nullptr)
                reversedHead = p;
            p->next = pre;
            pre = p;
            p = q;
        }
        return reversedHead;
    }
};