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
    TreeNode *isValid(vector<int> &preorder, int &index, int maxRang)
    {
        if (index >= preorder.size() || preorder[index] > maxRang) return NULL;

        TreeNode *root = new TreeNode(preorder[index++]);

        root->left = isValid(preorder, index, root->val);
        root->right = isValid(preorder, index, maxRang);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() < 0) return NULL;
        int index = 0;
        return isValid(preorder, index, INT_MAX);
    }
};
int main()
{
    Solution s;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    cout << "Construct Binary Search Tree from Preorder Traversal : " << endl;
    TreeNode *root = s.bstFromPreorder(preorder);
    cout << root->val << endl;

    cout << root->left->val << " ";
    cout << root->right->val << endl;

    cout << root->left->left->val << " ";
    cout << root->left->right->val << " ";
    cout << root->right->right->val << endl;
    return 0;
}