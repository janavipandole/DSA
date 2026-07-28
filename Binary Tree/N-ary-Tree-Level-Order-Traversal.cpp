#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++)
            {
                Node *node = q.front();
                q.pop();

                for (auto child : node->children)
                {
                    q.push(child);
                }

                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);

    Node *node3 = new Node(3);
    Node *node2 = new Node(2);
    Node *node4 = new Node(4);

    Node *node5 = new Node(5);
    Node *node6 = new Node(6);

    root->children = {node3, node2, node4};
    node3->children = {node5, node6};

    Solution s;
    cout << "N-ary Tree Level Order Traversal : " << endl;
    vector<vector<int>> ans = s.levelOrder(root);

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