#include <iostream>
#include <vector>
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
    void preOrder(TreeNode *root, int &totalSum, int low, int high)
    {
        if (root == nullptr) return;

        if (root->val <= high && root->val >= low)
        {
            totalSum += root->val;
        }

        preOrder(root->left, totalSum, low, high);
        preOrder(root->right, totalSum, low, high);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int totalSum = 0;

        if (!root)return 0;

        preOrder(root, totalSum, low, high);

        return totalSum;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(18);

    Solution s;

    int low = 7, high = 15;
    cout << "Range Sum of BST : " << s.rangeSumBST(root, low, high) << endl;

    return 0;
}