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

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
    TreeLinkNode *Next = nullptr;
    if (pNode == nullptr)
        return nullptr;
    if (pNode->right)
    {
        Next = pNode->right;
        while (Next->left)
        {
            Next = Next->left;
        }
    }
    else if (pNode->next)
    {
        Next = pNode->next;
        TreeLinkNode *Parent = Next;
        if (pNode == Parent->right)
        {
            while (Parent && Parent->right == pNode)
            {
                pNode = pNode->next;
                Parent = Parent->next;
            }
            if (Parent)
                Next = Parent;
            else
                return nullptr;
        }
    }
    return Next;
}