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
    TreeNode *help(TreeNode *root)
    {
        if (!root->left) return root->right;
        else if (!root->right)return root->left;

        TreeNode *rightChild = root->right;
        TreeNode *lastChild = findLastRight(root->left);
        lastChild->right = rightChild;
        return root->left;
    }
    TreeNode *findLastRight(TreeNode *root){
        if(!root->right) return root;
        return findLastRight(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (root->val == key) return help(root);

        TreeNode *dummy = root;
        while (root)
        {
            if (root->val > key)
            {
                if (root->left && root->left->val == key) {
                    root->left = help(root->left);
                    break;
                }
                else root = root->left;
            }
            else
            {
                if (root->right && root->right->val == key){
                    root->right = help(root->right);
                    break;
                }
                else root = root->right;
            }
        }
        return dummy; 
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution s;
    cout << "Delete Node in a Binary Search Tree : " << endl;
    cout << s.deleteNode(root, 4)->val << endl;

    return 0;
}