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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return p == q;
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    struct TreeNode *p = new TreeNode(3);

    p->left = new TreeNode(9);

    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);

    struct TreeNode *q = new TreeNode(3);

    q->left = new TreeNode(9);

    q->right = new TreeNode(20);
    q->right->left = new TreeNode(15);
    q->right->right = new TreeNode(7);

    Solution s;
    cout << "Same Tree : " << s.isSameTree(p,q) << endl;

    return 0;
}