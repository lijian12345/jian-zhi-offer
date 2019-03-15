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

struct ListNode
{
    int val;
    ListNode *next;
};

void PrintListReversingly_Iteratively(ListNode *pHead)
{
    stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while (!nodes.emplace())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->val);
        nodes.pop();
    }
}

vector<int> printListFromTailToHead(ListNode *head)
{
    vector<int> v;
    stack<ListNode *> s;
    ListNode *p = head;
    while (p != nullptr)
    {
        s.push(p);
        p = p->next;
    }
    while (!s.empty())
    {
        v.push_back(s.top()->val);
        s.pop();
    }
    return v;
}