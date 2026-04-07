#include <iostream>
#include <stack>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void changeTree(BinaryTreeNode *root)
    {
        if (root == NULL) return;

        int child = root->left ? root->left->data : 0;
        child += root->right ? root->right->data : 0;

        if (child >= root->data)root->data = child;
        else
        {
            if (root->left) root->left->data = root->data;
            if (root->right) root->right->data = root->data;
        }

        changeTree(root->left);
        changeTree(root->right);

        int totalSum = 0;
        if (root->left) totalSum += root->left->data;
        if (root->right) totalSum += root->right->data;
        if (root->left or root->right)root->data = totalSum;
    }
};
int main()
{
    BinaryTreeNode *root = new BinaryTreeNode(2);
    root->left = new BinaryTreeNode(35);
    root->right = new BinaryTreeNode(10);
    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(3);
    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(2);

    Solution s;
    cout << "Children Sum Property : " << endl;
    s.changeTree(root);
    cout << root->data << endl;
    cout << root->left->data << " " << root->right->data << endl;
    cout << root->left->left->data << " ";
    cout << root->left->right->data << " ";
    cout << root->right->left->data << " ";
    cout << root->right->right->data << endl;

    return 0;
}