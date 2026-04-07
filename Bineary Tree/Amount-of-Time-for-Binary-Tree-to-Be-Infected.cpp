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
    void markParentPointer(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mark_parent)
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
    bool getStartPointer(TreeNode *root, int &start, TreeNode *&node)
    {
        if (root == nullptr)return false;

        if (root->val == start)
        {
            node = root;
            return true;
        }

        if (getStartPointer(root->left, start, node) || getStartPointer(root->right, start, node)) return true;

        return false;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        if (!root) return 0;

        unordered_map<TreeNode *, TreeNode *> mark_parent;
        markParentPointer(root, mark_parent);

        TreeNode *node;
        getStartPointer(root, start, node);
        queue<TreeNode *> q;
        q.push(node);
        unordered_map<TreeNode *, bool> visited;
        visited[node] = true;

        int currentLevel = -1;

        while (!q.empty())
        {
            int size = q.size();
            currentLevel++;

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

        return currentLevel;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Amount of Time for Binary Tree to Be Infected : " << s.amountOfTime(root, 2) << endl;

    return 0;
}