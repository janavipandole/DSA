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
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        if (root == NULL) return ans;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            int Min = q.front().second;

            int first = 0, last = 0;

            for (int i = 0; i < size; i++)
            {
                long long int curr_idx = q.front().second - Min;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0) first = curr_idx;
                if (i == size - 1) last = curr_idx;

                if (node->left) q.push({node->left, curr_idx * 2 + 1});
                if (node->right) q.push({node->right, curr_idx * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    Solution s;
    cout << "Maximum Width of Binary Tree : " << s.widthOfBinaryTree(root) << endl;

    return 0;
}