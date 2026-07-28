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
    bool isSymmetricChecker(TreeNode *Left, TreeNode *Right)
    {
        if (Left == NULL || Right == NULL) return Left == Right ;

        if (Left->val != Right->val) return false;

        return isSymmetricChecker(Left->left, Right->right) && isSymmetricChecker(Left->right, Right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return root == NULL || isSymmetricChecker(root->left, root->right);
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution s;
    cout << "Symmetric Tree : " << s.isSymmetric(root) << endl;
    return 0;
}