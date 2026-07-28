#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    bool isSumProperty(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))return true;

        int sum = root->data;
        int lval = root->left ? root->left->data : 0;
        int rval = root->right ? root->right->data : 0;

        if (sum != lval + rval)return false;

        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(5);
    root->right = new Node(3);

    Solution s;
    cout << "Children Sum in a Binary Tree : " << s.isSumProperty(root) << endl;

    return 0;
}