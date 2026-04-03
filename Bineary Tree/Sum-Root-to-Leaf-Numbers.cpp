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
    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    void preOrder(TreeNode *root, int sum, int &totalSum)
    {
        if (root == nullptr) return;

        sum = ((sum * 10) + root->val);

        if (isLeaf(root))
        {
            totalSum += sum;
            return ;
        }

        preOrder(root->left, sum,totalSum);
        preOrder(root->right, sum,totalSum);
    }
    int sumNumbers(TreeNode *root)
    {
        int totalSum = 0;

        if (!root)return 0;

        preOrder(root, 0,totalSum);

        return totalSum;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(0);

    Solution s;
    cout <<"Sum Root to Leaf Numbers : " << s.sumNumbers(root)<< endl;

    return 0;
}