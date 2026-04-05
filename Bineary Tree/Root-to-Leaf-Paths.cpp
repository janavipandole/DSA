#include <iostream>
#include <vector>
using namespace std;

// Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    void preOrder(Node *root, vector<int> path, vector<vector<int>> &ans)
    {
        if (root == nullptr) return;

        path.push_back(root->data);

        if (isLeaf(root))
        {
            ans.push_back(path);
            return;
        }

        preOrder(root->left, path, ans);
        preOrder(root->right, path, ans);
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;

        if (!root) return ans;

        vector<int> path;
        preOrder(root, path, ans);

        return ans;
    }
};

int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    

    Solution s;
    cout << "Root to Leaf Paths : " << endl;
    vector<vector<int>> answer = s.Paths(root);

    for (auto ans : answer)
    {
        for (auto num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}