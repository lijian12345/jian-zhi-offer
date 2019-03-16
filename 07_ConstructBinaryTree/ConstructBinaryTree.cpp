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

struct BTNode
{
    int value;
    BTNode *left;
    BTNode *right;
};

BTNode *ConstructCore(int *startPre, int *endPre, int *startIn, int *endIn);

BTNode *Construct(int *pre, int *in, int length)
{
    if (pre == nullptr || in == nullptr || length <= 0)
        return nullptr;
    return ConstructCore(pre, pre + length - 1, in, in + length - 1);
}

BTNode *ConstructCore(int *startPre, int *endPre, int *startIn, int *endIn)
{
    int rootValue = startPre[0];
    BTNode *root = new BTNode();
    root->value = rootValue;
    root->left = root->right = nullptr;
    if (startPre == endPre)
    {
        if (startIn == endIn && *startPre == *startIn)
            return root;
        else
        {
            logic_error e("Invalid input.");
            throw exception(e);
        }
    }
    int *inRoot = startIn;
    while (inRoot <= endIn && *inRoot != rootValue)
        inRoot++;
    if (inRoot == endIn && *inRoot != rootValue)
    {
        logic_error e("Invalid input.");
        throw exception(e);
    }

    int leftLen = inRoot - startIn;
    int *leftEnd = startPre + leftLen;
    if (leftLen > 0)
    {
        root->left = ConstructCore(startPre + 1, leftEnd, startIn, inRoot - 1);
    }
    if (leftLen < endPre - startPre)
    {
        root->right = ConstructCore(leftEnd + 1, endPre, inRoot + 1, endIn);
    }
    return root;
}

//牛客
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    TreeNode* R(vector<int> a,int abegin,int aend,vector<int> b,int bbegin,int bend)
    {
        if(abegin>=aend || bbegin>=bend)
            return NULL;
        TreeNode* root=new TreeNode(a[abegin]);
        //root->val=a[abegin];
        int pivot;
        for(pivot=bbegin;pivot<bend;pivot++)
            if(b[pivot]==a[abegin])
                break;
        root->left=R(a,abegin+1,abegin+pivot-bbegin+1,b,bbegin,pivot);
        root->right=R(a,abegin+pivot-bbegin+1,aend,b,pivot+1,bend);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return R(pre,0,pre.size(),vin,0,vin.size());
    }

void printPre(TreeNode *root)
{
    if (root)
    {
        printf("%d ", root->val);
        printPre(root->left);
        printPre(root->right);
    }
}

void printPre(BTNode *root)
{
    if (root)
    {
        printf("%d ", root->value);
        printPre(root->left);
        printPre(root->right);
    }
}

int main()
{
    // int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    // int in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    // BTNode *root = Construct(pre, in, 8);
    // printPre(root);

    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> in = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *root = reConstructBinaryTree(pre, in);
    printPre(root);

    return 0;
}