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
    TreeNode *searchBSTBetter(TreeNode *root, int val)
    {
        if (root == NULL)return NULL;
        if (root->val == val)return root;

        if (val < root->val)root = searchBST1(root->left, val);
        else root = searchBST1(root->right, val);

        return root;
    }
    TreeNode *searchBSTOptimal(TreeNode *root, int val)
    {
        while (root != NULL && root->val != val)
        {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution s;
    cout << "Search in a Binary Search Tree : " << endl;
    TreeNode *node = s.searchBSTOptimal(root, 2);
    cout << node->val << endl;
    return 0;
}