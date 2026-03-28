#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};
class Solution1
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        if(abs(l-r) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        return true;
    }
};
class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = maxDepth(root->left);
        if(l == -1) return -1;

        int r = maxDepth(root->right);
        if(r == -1) return -1;

        if(abs(l-r) > 1) return -1;
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {
        return maxDepth(root) != -1;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution2 s;
    cout << "Maximum Depth of Binary Tree : " << s.isBalanced(root) << endl;

    return 0;
}