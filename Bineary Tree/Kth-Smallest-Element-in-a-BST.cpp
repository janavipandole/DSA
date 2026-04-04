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
    void preOrder(Node *root, priority_queue<int> &maxHeap, int k)
    {
        if (root == nullptr)
        {
            return;
        }

        maxHeap.push(root->data);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
        preOrder(root->left, maxHeap, k);
        preOrder(root->right, maxHeap, k);
    }
    int kthSmallest(Node *root, int k)
    {
        priority_queue<int> maxHeap;
        preOrder(root, maxHeap, k);
        return maxHeap.top();
    }
};
int main()
{
    struct Node *root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(4);

    root->left->right = new Node(2);

    Solution s;
    cout << "Kth Smallest Element in a BST : " << s.kthSmallest(root, 2) << endl;
    return 0;
}