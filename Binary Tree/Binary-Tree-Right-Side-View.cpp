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
    vector<int> rightSideView(Node *root)
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
            int y = val.second;

            if (mpp.find(y) == mpp.end())
                mpp[y] = node;

            if (node->right)
                q.push({node->right, y + 1});
            if (node->left)
                q.push({node->left, y + 1});
        }

        for (auto &[key, value] : mpp)
        {
            ans.push_back(value->data);
        }
        return ans;
    }
    void revPerOrder(Node *root, int level, vector<int> &ans)
    {
        if (root == NULL) return;

        if (level == ans.size()) ans.push_back(root->data);

        revPerOrder(root->right, level + 1, ans);
        revPerOrder(root->left, level + 1, ans);
    }
    vector<int> rightViewRecur(Node *root)
    {
        vector<int> ans;
        if (!root) return ans;

        revPerOrder(root,0,ans);
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    root->right = new Node(3);
    root->right->right = new Node(4);

    Solution s;
    cout << "Binary Tree Right Side View : " << endl;
    vector<int> ans = s.rightViewRecur(root);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}