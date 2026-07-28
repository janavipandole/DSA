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
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        if (root == nullptr) return ans;

        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
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
    root->left->right->right = new Node(6);

    Solution s;
    cout << "Morris traversal for Inorder : " << endl;
    vector<int> nums = s.inOrder(root);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}