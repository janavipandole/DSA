#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    void perOrderForLevel(Node *root, int level, int &maxLevel)
    {
        if (root == NULL)
        {
            return;
        }

        maxLevel = max(maxLevel, level);

        perOrderForLevel(root->left, level + 1, maxLevel);
        perOrderForLevel(root->right, level + 1, maxLevel);
    }
    void perOrderForSum(Node *root, int level, int &maxLevel, int &maxLevelSum)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == maxLevel)
        {
            maxLevelSum += root->data;
        }

        perOrderForSum(root->left, level + 1, maxLevel, maxLevelSum);
        perOrderForSum(root->right, level + 1, maxLevel, maxLevelSum);
    }
    int deepestLeavesSum(Node *root)
    {
        int maxLevel = 0;
        int maxLevelSum = 0;
        if (!root)
        {
            return maxLevelSum;
        }
        perOrderForLevel(root, 0, maxLevel);

        perOrderForSum(root, 0, maxLevel, maxLevelSum);

        return maxLevelSum;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);

    root->right->right = new Node(6);
    root->right->right->right = new Node(8);


    Solution s;
    cout << "Deepest Leaves Sum : " << s.deepestLeavesSum(root) << endl;
    return 0;
}