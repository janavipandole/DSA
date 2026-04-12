#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
class Solution
{
public:
    bool isValid(Node *root, long long minRang, long long maxRang)
    {
        if (!root) return true;

        if (root->data >= maxRang || root->data <= minRang) return false;

        return isValid(root->left, minRang, root->data) &&
        isValid(root->right, root->data, maxRang);
    }
    bool isValidBST(Node *root)
    {
        return isValid(root, LLONG_MIN ,LLONG_MAX);
    }
};
int main()
{
    struct Node *root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(4);

    root->left->right = new Node(2);

    Solution s;
    cout << "Validate Binary Search Tree : " << s.isValidBST(root) << endl;
    return 0;
}