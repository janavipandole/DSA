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
class SolutionBetter
{
public:
    int findFloor(TreeNode *root, int val)
    {
        int ceil = -1;
        while (root)
        {
            if (root->val == val)
            {
                ceil = root->val;
                return ceil;
            }

            if (val < root->val)
            {
                root = root->left;
            }
            else
            {
                ceil = root->val;
                root = root->right;
            }
        }
        return ceil;
    }
    int findCeil(TreeNode *root, int val)
    {
        int ceil = -1;

        while (root)
        {
            if (root->val == val)
            {
                ceil = root->val;
                return ceil;
            }

            if (val < root->val)
            {
                ceil = root->val;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return ceil;
    }
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<vector<int>> ans;
        for (auto querie : queries)
        {
            ans.push_back({findFloor(root, querie), findCeil(root, querie)});
        }
        return ans;
    }
};

class SolutionOptimal
{
public:
    void inOrder(TreeNode *root, vector<int> &nums)
    {
        if (!root)
        {
            return;
        }

        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    int findFloor(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int answer = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target)
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return answer;
    }
    int findCeil(vector<int> &nums, int &target, int low)
    {
        low = low == -1 ? 0 : low;
        int high = nums.size() - 1;
        int answer = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
            {
                answer = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return answer != -1 ? nums[answer] : -1;
    }
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<int> nums;
        inOrder(root, nums);

        vector<vector<int>> ans;
        for (auto querie : queries)
        {
            int val = findFloor(nums, querie);
            int num1 = val == -1 ? -1 : nums[val];
            ans.push_back({num1, findCeil(nums, querie, val)});
        }
        return ans;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(15);

    root->right->right->left = new TreeNode(14);

    SolutionOptimal s;
    vector<int> queries = {2, 5, 16};
    cout << "Closest Nodes Queries in a Binary Search Tree : " << endl;
    vector<vector<int>> ans = s.closestNodes(root, queries);
    for (auto nums : ans)
    {
        cout << nums[0] << " " << nums[1] << endl;
    }
    return 0;
}