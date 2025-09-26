#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int pascalElem(int row, int col)
    {
        int n = row - 1;
        int r = col - 1;
        int ans = 1;
        for (int i = 0; i < r; i++)
        {
            ans *= (n - i);
            ans /= i + 1;
        }
        return ans;
    }

    vector<int> pascalRowBrute(int row)
    {
        vector<int> ans;
        for (int i = 1; i <= row; i++)
        {
            ans.push_back(pascalElem(row, i));
        }
        return ans;
    }

    vector<int> pascalRowOptimal(int row)
    {
        vector<int> ans;
        int val = 1;
        ans.push_back(val);
        for (int i = 1; i < row; i++)
        {
            val *= row - i;
            val /= i;
            ans.push_back(val);
        }
        return ans;
    }

    vector<vector<int>> pascalTriangleBrute(int row)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= row; i++)
        {
            vector<int> temp;
            for (int j = 1; j <= i; j++)
            {
                temp.push_back(pascalElem(i, j));
            }
            ans.push_back(temp);
        }
        return ans;
    }

    vector<vector<int>> pascalTriangleOptimal(int row)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= row; i++)
        {
            ans.push_back(pascalRowOptimal(i));
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout << "pascal Elem : " << s.pascalElem(5, 3) << endl;
    vector<int> nums1 = s.pascalRowBrute(5);
    vector<int> nums2 = s.pascalRowOptimal(6);
    for (auto num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<vector<int>> nums4 = s.pascalTriangleOptimal(5);
    for (auto num : nums4)
    {
        for (auto n : num)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}