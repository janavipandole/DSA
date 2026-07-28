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
    bool evaluateTree(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL) return root;

        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        if (root->val == 2) return leftVal || rightVal;
        if (root->val == 3) return leftVal && rightVal;

        return root->val;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution s;
    cout<<"Evaluate Boolean Binary Tree : "<<endl;
    cout << s.evaluateTree(root) << endl;
    return 0;
}