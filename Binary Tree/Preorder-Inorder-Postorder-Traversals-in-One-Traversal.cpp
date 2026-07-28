#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class Solution
{
public:
    void InPrePostTraversal(TreeNode *root)
    {
        vector<int> Inorder, Preorder, Postorder;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        while (!st.empty())
        {
            if (st.top().second == 1)
            {
                Preorder.push_back(st.top().first->val);
                st.top().second++;
                if (st.top().first->left != NULL)
                {
                    st.push({st.top().first->left, 1});
                }
            }
            else if (st.top().second == 2)
            {
                Inorder.push_back(st.top().first->val);
                st.top().second++;
                if (st.top().first->right != NULL)
                {
                    st.push({st.top().first->right, 1});
                }
            }
            else
            {
                Postorder.push_back(st.top().first->val);
                st.pop();
            }
        }
        cout << "Inorder Traversal" << endl;
        for (auto num : Inorder)
        {
            cout << num << " ";
        }
        cout << endl;

        cout << "Preorder Traversal" << endl;
        for (auto num : Preorder)
        {
            cout << num << " ";
        }
        cout << endl;

        cout << "Postorder Traversal" << endl;
        for (auto num : Postorder)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Preorder Inorder Postorder Traversals in One Traversal : " << endl;
    s.InPrePostTraversal(root);
    return 0;
}