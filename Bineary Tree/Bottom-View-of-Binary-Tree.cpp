#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        map<int, Node *> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto val = q.front();
            q.pop();

            auto node = val.first;
            int x = val.second;

            mpp[x] = node;
            if (node->left) q.push({node->left, x - 1});
            if (node->right) q.push({node->right, x + 1});
        }

        for (auto &[key, value] : mpp)
        {
            ans.push_back(value->data);
        }
        return ans;
    }
};
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(90);
    root->right->right = new Node(100);

    Solution s;
    cout << "Bottom View of Binary Tree : " << endl;
    vector<int> ans = s.topView(root);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}