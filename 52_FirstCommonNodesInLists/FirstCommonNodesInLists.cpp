struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int len1 = getLen(pHead1);
        int len2 = getLen(pHead2);
        ListNode *p = pHead1, *q = pHead2;
        int lenDif = 0;
        if (len1 > len2)
        {
            lenDif = len1 - len2;
            for (int i = 0; i < lenDif; ++i)
                p = p->next;
        }
        if (len1 < len2)
        {
            lenDif = len2 - len1;
            for (int i = 0; i < lenDif; ++i)
                q = q->next;
        }
        while (p && q && p->val != q->val)
        {
            p = p->next;
            q = q->next;
        }
        ListNode *common = p;
        return common;
    }

    int getLen(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};

class Solution1
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        while (p != q)
        {
            p = (p == nullptr ? pHead2 : p->next);
            q = (q == nullptr ? pHead1 : q->next);
        }
        return p;
    }
};