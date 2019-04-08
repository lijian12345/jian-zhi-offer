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
    vector<vector<int>> buffer;
    vector<int> tmp;
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        if (root == nullptr)
            return buffer;
        tmp.push_back(root->val);
        if (expectNumber == root->val && root->left == nullptr && root->right == nullptr)
            buffer.push_back(tmp);
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);
        if (tmp.size())
            tmp.pop_back();
        return buffer;
    }
};