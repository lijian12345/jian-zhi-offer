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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> v;
        if (root == nullptr)
            return v;
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            v.push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
            q.pop();
        }
        return v;
    }
};