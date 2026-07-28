#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
    void markParentPointer(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mark_parent, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            if (current->left)
            {
                mark_parent[current->left] = current;
                q.push(current->left);
            }
            if (current->right)
            {
                mark_parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;

        if (!root)return ans;

        unordered_map<TreeNode *, TreeNode *> mark_parent;
        markParentPointer(root, mark_parent, target);

        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> visited;
        visited[target] = true;

        int currentLevel = 0;

        while (!q.empty())
        {
            int size = q.size();
            if (currentLevel++ == k) break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                if (current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (mark_parent[current] && !visited[mark_parent[current]])
                {
                    q.push(mark_parent[current]);
                    visited[mark_parent[current]] = true;
                }
            }
        }

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution s;
    cout << "All Nodes Distance K in Binary Tree : " << endl;
    vector<int> ans = s.distanceK(root,root->left,2);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}