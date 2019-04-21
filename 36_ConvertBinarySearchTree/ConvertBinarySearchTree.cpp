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
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (!pRootOfTree)
            return nullptr;
        TreeNode *pre = nullptr;
        ConvertNode(pRootOfTree, pre);
        TreeNode *res = pRootOfTree;
        while (res->left)
            res = res->left;
        return res;
    }
    void ConvertNode(TreeNode *cur, TreeNode *&pre)
    {
        if (!cur)
            return;
        ConvertNode(cur->left, pre);
        cur->left = pre;
        if (pre)
            pre->right = cur;
        pre = cur;
        ConvertNode(cur->right, pre);
    }
};