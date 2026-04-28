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

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return NULL;

        if (original == target) return cloned;

        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;

        return getTargetCopy(original->right, cloned->right, target);
    }
};
int main()
{
    struct TreeNode *original = new TreeNode(1);
    original->left = new TreeNode(2);
    original->right = new TreeNode(3);

    original->left->left = new TreeNode(4);
    original->left->right = new TreeNode(5);

    struct TreeNode *cloned = new TreeNode(1);
    cloned->left = new TreeNode(2);
    cloned->right = new TreeNode(3);

    cloned->left->left = new TreeNode(4);
    cloned->left->right = new TreeNode(5);

    Solution s;
    cout << "Find a Corresponding Node of a Binary Tree in a Clone of That Tree : " << s.getTargetCopy(original, cloned, original->left)->val << endl;

    return 0;
}