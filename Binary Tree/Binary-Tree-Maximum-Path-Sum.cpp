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
class Solution
{
public:
    int maxDepth(TreeNode *root, int &pathSum)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lSum = maxDepth(root->left, pathSum);
        int rSum = maxDepth(root->right, pathSum);

        if(lSum < 0) lSum = 0;
        if(rSum < 0) rSum = 0;
        pathSum = max(pathSum, lSum + rSum + root->val);

        return root->val + max(lSum, rSum);
    }

    int maxPathSum(TreeNode *root)
    {
        int pathSum = INT_MIN;
        maxDepth(root, pathSum);

        return pathSum;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Binary Tree Maximum Path Sum : " << s.maxPathSum(root) << endl;

    return 0;
}