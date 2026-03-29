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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)return ans;
        int flag = 0;
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
            if(flag == 0){
                ans.push_back(level);
                flag = 1;
            }else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
                flag = 0;
            }
        }

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
    cout << "Binary Tree Zigzag Level Order Traversal : " << endl;
    vector<vector<int>> ans = s.zigzagLevelOrder(root);

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