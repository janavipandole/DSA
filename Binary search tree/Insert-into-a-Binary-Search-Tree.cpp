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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)return new TreeNode(val);

        TreeNode *temp = root;

        while (temp)
        {
            if (temp->val <= val)
            {
                if (temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
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
    cout << "Insert into a Binary Search Tree : " << endl;
    cout << s.insertIntoBST(root, 5)->val<<endl;

    return 0;
}