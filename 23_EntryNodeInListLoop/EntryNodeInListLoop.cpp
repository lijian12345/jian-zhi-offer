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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *meetingNode = MeetingNode(pHead);
        if (meetingNode == nullptr)
            return nullptr;
        //环中节点数
        int nodesInLoop = 1;
        ListNode *pNode1 = meetingNode;
        while (pNode1->next != meetingNode)
        {
            pNode1 = pNode1->next;
            nodesInLoop++;
        }
        //先移动pNode1，次数为环中节点数
        pNode1 = pHead;
        for (int i = 0; i < nodesInLoop; i++)
        {
            pNode1 = pNode1->next;
        }
        //在移动pNode1和pNode2
        ListNode *pNode2 = pHead;
        while (pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }

    ListNode *MeetingNode(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode *pSlow = pHead->next;
        if (pSlow == nullptr)
            return nullptr;
        ListNode *pFast = pSlow->next;
        while (pFast && pSlow)
        {
            if (pFast == pSlow)
                return pFast;
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast)
                pFast = pFast->next;
        }
        return nullptr;
    }
};