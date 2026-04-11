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
    int findMaxFork(Node *root, int val)
    {

        int floor = -1;
        while (root)
        {
            if (root->data == val)
            {
                floor = root->data;
                return floor;
            }

            if (val < root->data)
            {
                root = root->left;
            }
            else
            {
                floor = root->data;
                root = root->right;
            }
        }
        return floor;
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
    cout << "Floor in a Binary Search Tree : " << s.findMaxFork(root, 5) << endl;

    return 0;
}