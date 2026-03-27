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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Binary Tree Level Order Traversal II (BST) : " << endl;
    vector<vector<int>> ans = s.levelOrderBottom(root);

    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}