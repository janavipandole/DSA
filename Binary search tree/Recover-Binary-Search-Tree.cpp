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
    TreeNode *prev;
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;

public:
    void inOrder(TreeNode *root)
    {
        if (!root) return;

        inOrder(root->left);
        if (prev != NULL && root->val < prev->val)
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;

        prev = new TreeNode(INT_MIN);
        inOrder(root);

        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    Solution s;
    cout << "Recover Binary Search Tree : " << endl;
    s.recoverTree(root);
    cout<<root->val<<endl;
    return 0;
}