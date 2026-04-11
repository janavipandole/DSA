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
    int rob(TreeNode *root)
    {
        if (root == NULL)return 0;

        queue<TreeNode *> q;

        q.push(root);
        int sumEven = 0;
        int sumOdd = 0;
        int count = 0;

        while (!q.empty())
        {
            int n = q.size();
            count++;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (count % 2 == 0)sumEven += node->val;
                else sumOdd += node->val;

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
        }

        return max(sumEven, sumOdd);
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(3);


    Solution s;
    cout << "House Robber III : " << s.rob(root) << endl;

    return 0;
}