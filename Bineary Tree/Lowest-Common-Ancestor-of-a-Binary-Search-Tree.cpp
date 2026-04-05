#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1
{
public:
    bool preOrder(TreeNode *root, vector<TreeNode *> &path, TreeNode *node)
    {
        if (root == nullptr) return false;

        path.push_back(root);

        if (root->val == node->val) return true;

        if (preOrder(root->left, path, node) || preOrder(root->right, path, node)) return true;

        path.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)return root;

        vector<TreeNode *> val1;
        vector<TreeNode *> val2;

        preOrder(root, val1, p);
        preOrder(root, val2, q);

        TreeNode *temp = root;

        for (int i = 0; i < min(val1.size(), val2.size()); i++)
        {
            if (val1[i]->val == val2[i]->val) temp = val1[i];
            else return temp;
        }

        return temp;
    }
};

class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(!left) return right;
        else if(!right) return left;
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution2 s;
    cout << "Lowest Common Ancestor of a Binary Search Tree : " << s.lowestCommonAncestor(root, root->left->left, root->left->right->right)->val << endl;
    return 0;
}