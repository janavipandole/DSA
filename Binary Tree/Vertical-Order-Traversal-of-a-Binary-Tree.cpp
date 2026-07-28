#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

//   Definition for a binary tree node.
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mapping;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto start = q.front();
            q.pop();

            TreeNode *node = start.first;
            int x = start.second.first;
            int y = start.second.second;

            mapping[x][y].insert(node->val);

            if (node->left)
            {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto mpp : mapping)
        {
            vector<int> cols;
            for (auto val : mpp.second)
            {
                cols.insert(cols.end(), val.second.begin(), val.second.end());
            }
            ans.push_back(cols);
        }

        return ans;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Vertical Order Traversal of a Binary Tree : " << endl;
    vector<vector<int>> ans = s.verticalTraversal(root);

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