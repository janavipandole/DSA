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
    void perOrder(Node *root, int level, int &ans, int &maxLevel)
    {
        if (root == NULL)
        {
            return;
        }

        if (level > maxLevel)
        {
            maxLevel = level;
            ans = root->data;
        }

        perOrder(root->left, level + 1, ans, maxLevel);
        perOrder(root->right, level + 1, ans, maxLevel);
    }
    int findBottomLeftValue(Node *root)
    {
        int ans = -1;
        int maxLevel = -1;
        perOrder(root, 0, ans, maxLevel);
        return ans;
    }
};
int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(90);
    root->right->left->right = new Node(100);

    Solution s;
    cout << "Find Bottom Left Tree Value : " << s.findBottomLeftValue(root) << endl;
    return 0;
}