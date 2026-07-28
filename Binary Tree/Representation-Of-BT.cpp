#include <iostream>
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
void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << "->";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << "->";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "->";
}
int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Depth First Search (DFS): " << endl;
    cout << "preOrder traverseal : ";
    preOrder(root);
    cout << endl;

    cout << "inOrder traverseal : ";
    inOrder(root);
    cout << endl;

    cout << "postOrder traverseal : ";
    postOrder(root);
    cout << endl;

    cout<<endl << "Breadth First Search (BFS): " << endl;
    return 0;
}