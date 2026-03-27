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
    void postOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    cout << "Binary Tree Postorder Traversal : " << endl;
    vector<int> ans = s.postorderTraversal(root);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}