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
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        int depth = 0;
        return IsBalanced(pRoot, depth);
    }

    bool IsBalanced(TreeNode *root, int &depth)
    {
        if (root == nullptr)
        {
            depth = 0;
            return true;
        }
        int left, right;
        if (IsBalanced(root->left, left) && IsBalanced(root->right, right))
        {
            int diff = left - right;
            if (diff <= 1 && diff >= -1)
            {
                depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};