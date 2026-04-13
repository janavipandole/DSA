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
class BSTIterator1
{
    queue<int> q;

public:
    BSTIterator1(TreeNode *root)
    {
        inOrder(root, q);
    }
    void inOrder(TreeNode *root, queue<int> &q)
    {
        if (!root)
            return;

        inOrder(root->left, q);
        q.push(root->val);
        inOrder(root->right, q);
    }
    int next()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    bool hasNext()
    {
        if (q.empty())
            return false;

        return true;
    }
};

class BSTIterator2
{
    stack<TreeNode *> st;

public:
    BSTIterator2(TreeNode *root)
    {
        pushAll(root);
    }
    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }

    bool hasNext()
    {
        if (st.empty()) return false;

        return true;
    }

private:
    void pushAll(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
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

    BSTIterator2 *obj = new BSTIterator2(root);
    cout << "Binary Search Tree Iterator : " << endl;
    cout << obj->next() << endl;
    return 0;
}