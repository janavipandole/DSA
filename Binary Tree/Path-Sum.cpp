#include <iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    bool preOrder(TreeNode *root, int targetSum, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (isLeaf(root) && targetSum == sum)
        {
            return true;
        }

        if (root->left != NULL)
        {
            if (preOrder(root->left, targetSum, sum + root->left->val))
            {
                return true;
            }
        }
        if (root->right != NULL)
        {
            if (preOrder(root->right, targetSum, sum + root->right->val))
            {
                return true;
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }
        return preOrder(root, targetSum, root->val);
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution s;
    cout << "Path Sum : " << s.hasPathSum(root, 22) << endl;
    return 0;
}