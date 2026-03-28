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
class SolutionBrtue
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

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int Max = max(Max, left + right);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return Max;
    }
};

class SolutionOptimal
{
public:
    int maxDepth(TreeNode *root, int &maxDiameter)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = maxDepth(root->left, maxDiameter);
        int r = maxDepth(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, l + r);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxDiameter = 0;
        maxDepth(root, maxDiameter);

        return maxDiameter;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    SolutionOptimal s;
    cout << "Diameter of Binary Tree : " << s.diameterOfBinaryTree(root) << endl;

    return 0;
}