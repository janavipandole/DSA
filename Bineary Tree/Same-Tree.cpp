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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL) return p == q;   
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main()
{
    struct TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);

    struct TreeNode *q = new TreeNode(1);
    q->right = new TreeNode(2);

    Solution s;
    cout << "Same Tree : " << s.isSameTree(p, q) << endl;

    return 0;
}