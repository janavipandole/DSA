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
    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pre = NULL;
        Node *suc = NULL;
        Node *dummy = root;

        while (dummy)
        {
            if (key >= dummy->data)
            {
                dummy = dummy->right;
            }
            else
            {
                suc = dummy;
                dummy = dummy->left;
            }
        }

        while (root)
        {
            if (key > root->data)
            {
                pre = root;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        return {pre, suc};
    }
};
int main()
{
    struct Node *root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(4);

    root->left->right = new Node(2);

    Solution s;
    cout << "Inorder Successor and Predecessor in BST : " << endl;

    vector<Node *> ans = s.findPreSuc(root, 2);
    cout << ans[0]->data << " " << ans[1]->data << endl;
    return 0;
}