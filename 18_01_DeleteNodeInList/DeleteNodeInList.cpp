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

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if (!pListHead || !pToBeDeleted)
        return;
    // 要删除的不是尾结点
    if (pToBeDeleted->next)
    {
        ListNode *pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;
        delete pNext;
        pNext = nullptr;
    }
    // 只有一个节点，删除头节点
    else if (*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted=nullptr;
        *pListHead=nullptr;
    }
    //
    else{
        ListNode* pNode=*pListHead;
        
    }
}