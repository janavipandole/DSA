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
    int findleftHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    int findrightHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)return 0;

        int leftHeight = findleftHeight(root);
        int rightHeight = findrightHeight(root);

        if (leftHeight == rightHeight)return (1<<leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Count Complete Tree Nodes : " << s.countNodes(root) << endl;
    return 0;
}