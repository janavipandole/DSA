#include <iostream>
#include <vector>
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
    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    void preOrder(TreeNode *root, int &sum)
    {
        if (root == nullptr) return;

        if (isLeaf(root))
        {
            sum += root->val;
            return;
        }

        preOrder(root->left, sum);
        preOrder(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        {
            int sum = 0;
            if (!root || isLeaf(root)) return sum;

            preOrder(root, sum);

            return sum;
        }
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
   
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Sum of Left Leaves : " << s.sumOfLeftLeaves(root) << endl;

    return 0;
}