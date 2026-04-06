#include <iostream>
#include <queue>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)return NULL;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int level = q.size();

            for (int i = 0; i < level; i++)
            {
                Node *node = q.front();
                q.pop();

                if (i < level - 1) node->next = q.front();
                else node->next = NULL;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};

int main()
{
    struct Node *root = new Node(1);
    root->next = NULL;

    root->left = new Node(2);
    root->left->next = NULL;

    root->right = new Node(3);
    root->right->next = NULL;

    root->left->left = new Node(4);
    root->left->left->next = NULL;

    root->left->right = new Node(5);
    root->left->right->next = NULL;

    root->right->left = new Node(6);
    root->right->left->next = NULL;

    root->right->right = new Node(7);
    root->right->right->next = NULL;

    Solution s;
    cout << "Populating Next Right Pointers in Each Node : " << endl;
    cout << s.connect(root)->val << " " << root->left->val << " " << root->left->next->val << endl;
    return 0;
}