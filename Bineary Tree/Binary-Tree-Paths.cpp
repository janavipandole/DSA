#include <iostream>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    void preOrder(TreeNode *root, string str, vector<string> &ans)
    {
        if (root == nullptr)return;

        str = str + to_string(root->val) + "->";
        if (isLeaf(root))
        {
            str = str.substr(0,str.size()-2);
            ans.push_back(str);
            return;
        }

        preOrder(root->left, str, ans);
        preOrder(root->right, str, ans);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;

        if (!root) return ans;

        preOrder(root, "", ans);

        return ans;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(0);

    Solution s;
    cout << "Binary Tree Paths : " << endl;
    vector<string> str = s.binaryTreePaths(root);

    for (auto s : str)
    {
        cout << s << endl;
    }

    return 0;
}