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
    void inOrder(Node *root, int &k, int &ans)
    {
        if (root == nullptr)
            return;

        inOrder(root->right, k, ans);
        if (--k == 0)
        {
            ans = root->data;
            return;
        }
        inOrder(root->left, k, ans);
    }
    int kthLargest(Node *root, int k)
    {
        int ans = 0;
        int count = 0;
        inOrder(root, k, ans);
        return ans;
    }
};
int main()
{
    struct Node *root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(4);

    root->left->right = new Node(2);

    Solution s;
    cout << "Kth largest element in BST : " << s.kthLargest(root, 2) << endl;
    return 0;
}