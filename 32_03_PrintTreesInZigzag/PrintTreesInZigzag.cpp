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
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (pRoot == nullptr)
            return res;
        stack<TreeNode *> leftStack, rightStack;
        leftStack.push(pRoot);
        while (!leftStack.empty() || !rightStack.empty())
        {
            if (!leftStack.empty())
            {
                vector<int> temp;
                while (!leftStack.empty())
                {
                    TreeNode *data = leftStack.top();
                    leftStack.pop();
                    temp.push_back(data->val);
                    if (data->left)
                        rightStack.push(data->left);
                    if (data->right)
                        rightStack.push(data->right);
                }
                res.push_back(temp);
            }
            if (!rightStack.empty())
            {
                vector<int> temp;
                while (!rightStack.empty())
                {
                    TreeNode *data = rightStack.top();
                    rightStack.pop();
                    temp.push_back(data->val);
                    if (data->right)
                        leftStack.push(data->right);
                    if (data->left)
                        leftStack.push(data->left);
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};