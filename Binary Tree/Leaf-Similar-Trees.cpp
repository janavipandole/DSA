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
    bool isLeaf(TreeNode *root)
    {
        return root->left == nullptr && root->right == nullptr;
    }
    
    void travel(TreeNode *root, vector<int> &ans){
        if(!root) return;

        if(isLeaf(root)) ans.push_back(root->val);

        travel(root->left,ans);
        travel(root->right,ans);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2) return true;

        if (!root1) return false;

        if (!root2) return false;

        vector<int> nums1;
        travel(root1,nums1);

        vector<int> nums2;
        travel(root2,nums2);

        if (nums1.size() != nums2.size()) return false;

        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] != nums2[i]) return false;
        }
        return true;
    }
};
int main()
{
    struct TreeNode *root1 = new TreeNode(3);

    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);

    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);

    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);


    struct TreeNode *root2 = new TreeNode(3);

    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);

    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);

    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);

    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);


    Solution s;

    cout << "Leaf-Similar Trees : " << s.leafSimilar(root1, root2) << endl;

    return 0;
}