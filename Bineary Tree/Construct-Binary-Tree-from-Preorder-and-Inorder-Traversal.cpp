#include <iostream>
#include <unordered_map>
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
    TreeNode *buildTreeByPreInOrder(vector<int> &preorder, int startPre, int endPre, vector<int> &inorder, int startIn, int endIn,unordered_map<int, int> &hash)
    {
        if (startPre > endPre || startIn > endIn)return NULL;

        TreeNode *root = new TreeNode(preorder[startPre]);

        int RootIn = hash[root->val];
        int leftPre = RootIn - startIn;

        root->left = buildTreeByPreInOrder(preorder, startPre + 1, startPre + leftPre, inorder, startIn, RootIn - 1, hash);
        root->right = buildTreeByPreInOrder(preorder, startPre + leftPre + 1, endPre, inorder, RootIn + 1, endIn, hash);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++)
        {
            hash[inorder[i]] = i;
        }
        return buildTreeByPreInOrder(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, hash);
    }
};
int main()
{
    Solution s;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    cout << "Construct Binary Tree from Preorder and Inorder Traversal : " << endl;
    struct TreeNode *root = s.buildTree(preorder, inorder);
    cout << root->val << endl;
    cout << root->left->val << " " << root->right->val << endl;
    cout << root->right->left->val << " " << root->right->right->val << endl;
    return 0;
}