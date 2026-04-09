#include <iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    //    Solution 1
    void preOrder(TreeNode *root, vector<TreeNode *> &ans)
    {
        if (root == nullptr) return;

        ans.push_back(root);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    TreeNode *flate(TreeNode *root, vector<TreeNode *> &ans, int index)
    {
        if (index >= ans.size()) return NULL;

        root->left = NULL;
        root->right = ans[index];
        flate(root->right, ans, index + 1);
        return root;
    }
    void flatten1(TreeNode *root)
    {
        vector<TreeNode *> ans;
        preOrder(root, ans);
        root = flate(root, ans, 1);
    }
    //    Solution 2
    void flateList(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL) return;

        flateList(root->right, prev);
        flateList(root->left, prev);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void flatten2(TreeNode *root)
    {
        TreeNode *prev = NULL;
        flateList(root, prev);
    }
    //    Solution 3
    void flatten3(TreeNode *root)
    {
        if (!root) return;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            if (curr->right) st.push(curr->right);

            if (curr->left) st.push(curr->left);

            if (!st.empty()) curr->right = st.top();

            curr->left = NULL;
        }
    }
    //    Solution 4
    void flatten4(TreeNode *root)
    {
        if (root == NULL) return;

        TreeNode *curr = root;
        TreeNode *prev = curr;
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                prev = curr->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution s;
    cout << "Flatten Binary Tree to Linked List : " << endl;
    s.flatten4(root);
    cout << root->val << endl;
    cout << root->right->val << endl;
    cout << root->right->right->val << endl;
    cout << root->right->right->right->val << endl;
    cout << root->right->right->right->right->val << endl;
    cout << root->right->right->right->right->right->val << endl;

    return 0;
}