#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> answer;
        if(!root) return answer;
        
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                maxVal = max(maxVal, node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            answer.push_back(maxVal);
        }
        return answer;
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    Solution s;
    cout << "Find Largest Value in Each Tree Row : " << endl;
    vector<int> largestValue = s.largestValues(root);
    for (auto value : largestValue)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}