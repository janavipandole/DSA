#include <iostream>
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
    void preOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }

        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    vector<int> preorderTraversalSol1(TreeNode *root)
    {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }

    vector<int> preorderTraversalSol2(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();

            if (node->right != NULL) st.push(node->right);
            if (node->left != NULL) st.push(node->left);

            ans.push_back(node->val);
           
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
    cout << "Binary Tree Preorder Traversal : " << endl;
    vector<int> ans = s.preorderTraversalSol2(root);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}