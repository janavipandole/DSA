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
    TreeNode *buildTreeByPostInOrder(vector<int> &postorder, int startPre, int endPre, vector<int> &inorder, int startIn, int endIn, unordered_map<int, int> &hash)
    {
        if (startPre > endPre || startIn > endIn) return NULL;

        TreeNode *root = new TreeNode(postorder[endPre]);

        int RootIn = hash[root->val];
        int leftPre = RootIn - startIn;

        root->left = buildTreeByPostInOrder(postorder, startPre, startPre + leftPre - 1, inorder, startIn, RootIn - 1, hash);
        root->right = buildTreeByPostInOrder(postorder, startPre + leftPre, endPre - 1, inorder, RootIn + 1, endIn, hash);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++)
        {
            hash[inorder[i]] = i;
        }
        return buildTreeByPostInOrder(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, hash);
    }
};
int main()
{
    Solution s;

    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    cout << "Construct Binary Tree from Inorder and Postorder Traversal : " << endl;
    struct TreeNode *root = s.buildTree(inorder, postorder);
    cout << root->val << endl;
    cout << root->left->val << " " << root->right->val << endl;
    cout << root->right->left->val << " " << root->right->right->val << endl;
    return 0;
}