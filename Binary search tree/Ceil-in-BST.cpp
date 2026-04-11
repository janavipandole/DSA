#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
class Solution
{
public:
    int findCeil(Node *root, int val)
    {
        int ceil = -1;
        while (root)
        {
            if (root->data == val)
            {
                ceil = root->data;
                return ceil;
            }

            if (val < root->data)
            {
                ceil = root->data;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return ceil;
    }
};
int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution s;
    cout << "Ceil in a Binary Search Tree : " << s.findCeil(root, 5) << endl;

    return 0;
}