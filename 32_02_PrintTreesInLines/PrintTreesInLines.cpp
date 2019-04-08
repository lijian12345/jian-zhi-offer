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

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
  public:
    void PrintInLines(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root == nullptr)
            return;
        q.push(root);
        int nextLevel = 0;
        int toBePrinted = 1;
        while (!q.empty())
        {
            root = q.front();
            printf("%d ", root->val);
            if (root->left)
            {
                q.push(root->left);
                ++nextLevel;
            }
            if (root->right)
            {
                q.push(root->right);
                ++nextLevel;
            }
            q.pop();
            --toBePrinted;
            if (toBePrinted == 0)
            {
                printf("\n");
                toBePrinted = nextLevel;
                nextLevel = 0;
            }
        }
    }
};

class Solution1
{
  public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> ans;
        if (pRoot == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> levelElem;
            while (size--)
            {
                TreeNode *t = q.front();
                q.pop();
                levelElem.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ans.push_back(levelElem);
        }
        return ans;
    }
};