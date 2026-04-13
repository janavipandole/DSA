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
class BSTIterator
{
    stack<TreeNode *> st;
    bool isNext = true;

public:
    BSTIterator(TreeNode *root, bool state)
    {
        isNext = state;
        pushAll(root);
    }
    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        if (isNext) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

private:
    void pushAll(TreeNode *root)
    {
        while (root)
        {
            st.push(root);

            if (isNext) root = root->left;

            else root = root->right;
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator left(root, true);
        BSTIterator right(root, false);

        int next = left.next();
        int befor = right.next();

        while (next < befor)
        {
            if (next + befor == k) return true;
            else if (next + befor < k)next = left.next();
            else befor = right.next();
        }
        return false;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(15);

    root->right->right->left = new TreeNode(14);

    Solution s;
    cout << "Two Sum IV - Input is a BST : " << s.findTarget(root, 8) << endl;

    return 0;
}