#include <iostream>
using namespace std;

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
    void postOrder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        for (auto child : root->children)
        {
            postOrder(child, ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        postOrder(root, ans);
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
    cout << "N-ary Tree Postorder Traversal : " << endl;
    vector<int> ans = s.postorder(root);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}