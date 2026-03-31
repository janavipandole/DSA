#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    bool isLeaf(Node *node)
    {
        if (node->left == NULL && node->right == NULL) {
            return true;
        }
        return false;
    }
    void letfBoundary(Node *root, vector<int> &ans)
    {
        Node *current = root->left;
        while (current)
        {
            if (!isLeaf(current)) ans.push_back(current->data);
            if (current->left) current = current->left;
            else current = current->right;
        }
    }
    void leafBoundary(Node *root, vector<int> &ans)
    {
        if (isLeaf(root))
        {
            ans.push_back(root->data);
        }
        if (root->left) leafBoundary(root->left, ans);
        if (root->right) leafBoundary(root->right, ans);
    }

    void rightBoundary(Node *root, vector<int> &ans)
    {
        vector<int> temp;
        Node *current = root->right;
        while (current)
        {
            if (!isLeaf(current))temp.push_back(current->data);
            if (current->right)current = current->right;
            else current = current->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans.push_back(temp[i]);
        }
    }
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root))ans.push_back(root->data);
        letfBoundary(root, ans);
        leafBoundary(root, ans);
        rightBoundary(root, ans);
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    cout << "Tree Boundary Traversal : " << endl;
    vector<int> ans = s.boundaryTraversal(root);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}