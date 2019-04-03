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

ListNode *deleteDuplication(ListNode *pHead)
{
    ListNode *pre = nullptr;
    ListNode *p = pHead;   //current dealing
    ListNode *q = nullptr; //next to the current
    while (p)
    {
        if (p->next && p->next->val == p->val)
        {
            q = p->next;
            while (q && q->next && q->next->val == q->val)
            {
                q = q->next;
            }
            if (p == pHead)
            {
                pHead = q->next;
            }
            else
            {
                pre->next = q->next;
            }
            p = q->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return pHead;
}