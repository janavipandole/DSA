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
    int maxDepthRec(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = maxDepthRec(root->left);
        int r = maxDepthRec(root->right);

        return 1 + max(l, r);
    }
    int maxDepthLevelOrder(TreeNode *root)
    {
        int level = 0;
        queue<TreeNode *> q;

        q.push(root);

      
        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            level++;
        
        }

        return level;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    cout << "Maximum Depth of Binary Tree : " << s.maxDepthLevelOrder(root) << endl;

    return 0;
}