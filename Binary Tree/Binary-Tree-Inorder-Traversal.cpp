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
    void inOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    vector<int> inorderTraversalSol1(TreeNode *root)
    {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
    vector<int> inorderTraversalSol2(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *node = root;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty()) break;
                node = st.top();
                st.pop();

                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    cout << "Binary Tree Inorder Traversal : " << endl;
    vector<int> ans = s.inorderTraversalSol2(root);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}