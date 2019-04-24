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
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == nullptr || k == 0)
            return nullptr;
        return KthNodeCore(pRoot, k);
    }

    TreeNode *KthNodeCore(TreeNode *pRoot, int &k)
    {
        TreeNode *target = nullptr;
        if (pRoot->left)
            target = KthNodeCore(pRoot->left, k);
        if (target == nullptr)
        {
            if (k == 1)
                target = pRoot;
            k--;
        }
        if (target == nullptr && pRoot->right)
            target = KthNodeCore(pRoot->right, k);
        return target;
    }
};