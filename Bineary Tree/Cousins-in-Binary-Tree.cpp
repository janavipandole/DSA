#include <iostream>
using namespace std;

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
    bool depth(TreeNode *root, TreeNode *par, int val, int &Dis, TreeNode *&parent)
    {
        if (!root) return false;

        if (root->val == val)
        {
            parent = par;
            return true;
        }

        Dis += 1;

        if (depth(root->left, root, val, Dis, parent)) return true;
        if (depth(root->right, root, val, Dis, parent)) return true;

        Dis -= 1;
        return false;
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root)return false;

        TreeNode *parentX = root, *parentY = root;
        int Dis1 = 0, Dis2 = 0;

        depth(root, root, x, Dis1, parentX);
        depth(root, root, y, Dis2, parentY);

        return Dis1 == Dis2 && parentX != parentY;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    int x = 4, y = 5;
    Solution s;
    cout<<"Cousins in Binary Tree : "<<s.isCousins(root, x, y)<<endl;
    return 0;
}
